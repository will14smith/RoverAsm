.global handle_command

handle_command:
	// rdi = pointer to rover struct
        // rsi = command

	cmp $70, %rsi
	je handle_forward

	cmp $66, %rsi
	je handle_backward

	cmp $76, %rsi
	je handle_left

	cmp $82, %rsi
	je handle_right

	mov $1, %eax
	ret

handle_forward:
	// ecx = _move + rdi->d * 2
	mov 8(%rdi), %ecx
	shl $1, %ecx
	add $_move, %ecx

	// eax = _move[ecx]
	movsbl (%ecx), %eax
	// rdi.x = rdi.x + eax
	mov (%rdi), %edx
	add %eax, %edx
	mov %edx, (%rdi)
        // eax = _move[ecx+1]
        movsbl 1(%ecx), %eax
        // rdi.y = rdi.y + eax
        mov 4(%rdi), %edx
        add %eax, %edx
        mov %edx, 4(%rdi)

	mov $0, %eax
	ret

handle_backward:
        // ecx = _move + rdi->d * 2
        mov 8(%rdi), %ecx
        shl $1, %ecx
        add $_move, %ecx

        // eax = _move[ecx]
        movsbl (%ecx), %eax
        // rdi.x = rdi.x - eax
        mov (%rdi), %edx
        sub %eax, %edx
        mov %edx, (%rdi)
        // eax = _move[ecx+1]
        movsbl 1(%ecx), %eax
        // rdi.y = rdi.y - eax
        mov 4(%rdi), %edx
        sub %eax, %edx
        mov %edx, 4(%rdi)

        mov $0, %eax
        ret

handle_left:
handle_right:
	movl $2, %eax
	ret

.data

_move:
_move_N: .byte 0, 1
_move_E: .byte 1, 0
_move_S: .byte 0, -1
_move_W: .byte -1, 0
