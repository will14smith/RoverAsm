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
	mov 4(%rdi), %ecx
	add $1, %ecx
	mov %ecx, 4(%rdi)

	mov $0, %eax
	ret

handle_backward:
handle_left:
handle_right:
	movl $2, %eax
	ret
