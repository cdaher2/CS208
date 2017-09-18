//types.c
//displays the sizes of int, long int, and char variable types

#include <limits.h>

int printf(const char *format, ...);

int main(void) {
	printf("\n");
	printf("Size of int %d bytes\t", sizeof(int));
	printf("Maximum int: %d\n", INT_MAX);
	printf("Size of long: %d bytes\t", sizeof(long));
	printf("Maximum long: %ld\n", LONG_MAX);

	printf("Size of char %d byte \t", sizeof(char));
	printf("Maximum char: %d\t", CHAR_MAX);
	printf("Minimum char: %d\n", CHAR_MIN);
	puts("");
}
