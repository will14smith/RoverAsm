#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "main.h"

#define assertSuccess(X) assert((X) == RESULT_SUCCESS)
#define _assertR(X) do { if(!(X)) { printf("Expected: "); print_rover(e); printf("Actual: "); print_rover(a); assert(X); } } while(0);
#define assertRover(E, A) do { rover_t e = (E); rover_t a = (A); _assertR(e.x == a.x); _assertR(e.y == a.y); _assertR(e.d == a.d); } while(0)

void print_rover(rover_t rover) {
	printf("(%i,%i) %i\n", rover.x, rover.y, rover.d);
}

void test_forward_N() {
	rover_t rover = {0,0,DIR_NORTH};
	rover_t expected = {0,1,DIR_NORTH};

	assertSuccess(handle_command(&rover, 'F'));
	assertRover(expected, rover);
}
void test_forward_E() {
        rover_t rover = {0,0,DIR_EAST};
        rover_t expected = {1,0,DIR_EAST};

        assertSuccess(handle_command(&rover, 'F'));
        assertRover(expected, rover);
}
void test_forward_S() {
        rover_t rover = {0,0,DIR_SOUTH};
        rover_t expected = {0,-1,DIR_SOUTH};

        assertSuccess(handle_command(&rover, 'F'));
        assertRover(expected, rover);
}
void test_forward_W() {
        rover_t rover = {0,0,DIR_WEST};
        rover_t expected = {-1,0,DIR_WEST};

        assertSuccess(handle_command(&rover, 'F'));
        assertRover(expected, rover);
}

void test_backward_N() {
        rover_t rover = {0,0,DIR_NORTH};
        rover_t expected = {0,-1,DIR_NORTH};

        assertSuccess(handle_command(&rover, 'B'));
        assertRover(expected, rover);
}
void test_backward_E() {
        rover_t rover = {0,0,DIR_EAST};
        rover_t expected = {-1,0,DIR_EAST};

        assertSuccess(handle_command(&rover, 'B'));
        assertRover(expected, rover);
}
void test_backward_S() {
        rover_t rover = {0,0,DIR_SOUTH};
        rover_t expected = {0,1,DIR_SOUTH};

        assertSuccess(handle_command(&rover, 'B'));
        assertRover(expected, rover);
}
void test_backward_W() {
        rover_t rover = {0,0,DIR_WEST};
        rover_t expected = {1,0,DIR_WEST};

        assertSuccess(handle_command(&rover, 'B'));
        assertRover(expected, rover);
}

void test_left_N() {
        rover_t rover = {0,0,DIR_NORTH};
        rover_t expected = {0,0,DIR_EAST};

        assertSuccess(handle_command(&rover, 'L'));
        assertRover(expected, rover);
}
void test_left_E() {
        rover_t rover = {0,0,DIR_EAST};
        rover_t expected = {0,0,DIR_SOUTH};

        assertSuccess(handle_command(&rover, 'L'));
        assertRover(expected, rover);
}
void test_left_S() {
        rover_t rover = {0,0,DIR_SOUTH};
        rover_t expected = {0,0,DIR_WEST};

        assertSuccess(handle_command(&rover, 'L'));
        assertRover(expected, rover);
}
void test_left_W() {
        rover_t rover = {0,0,DIR_WEST};
        rover_t expected = {0,0,DIR_NORTH};

        assertSuccess(handle_command(&rover, 'L'));
        assertRover(expected, rover);
}

void test_right_N() {
        rover_t rover = {0,0,DIR_NORTH};
        rover_t expected = {0,0,DIR_WEST};

        assertSuccess(handle_command(&rover, 'R'));
        assertRover(expected, rover);
}
void test_right_E() {
        rover_t rover = {0,0,DIR_EAST};
        rover_t expected = {0,0,DIR_NORTH};

        assertSuccess(handle_command(&rover, 'R'));
        assertRover(expected, rover);
}
void test_right_S() {
        rover_t rover = {0,0,DIR_SOUTH};
        rover_t expected = {0,0,DIR_EAST};

        assertSuccess(handle_command(&rover, 'R'));
        assertRover(expected, rover);
}
void test_right_W() {
        rover_t rover = {0,0,DIR_WEST};
        rover_t expected = {0,0,DIR_SOUTH};

        assertSuccess(handle_command(&rover, 'R'));
        assertRover(expected, rover);
}

int main() {
	test_forward_N();
	test_forward_E();
	test_forward_S();
	test_forward_W();

	test_backward_N();
	test_backward_E();
	test_backward_S();
	test_backward_W();

	test_left_N();
	test_left_E();
	test_left_S();
	test_left_W();

	test_right_N();
	test_right_E();
	test_right_S();
	test_right_W();

	return 0;
}
