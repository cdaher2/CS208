// itoa1.c
//does what itoa0.c does using cs212lib
//Christian Daher 9/24/17

#include "cs212lib.h"

int printf(char* format, ...);

int main(void) {
	printf("%s\n", itoa(123,6));
	printf("%s\n", itoa(1523,6));
}
