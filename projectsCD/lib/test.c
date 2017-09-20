#include "cs212lib.h"

int main(void) {
	char* f = itoa(23,2);
	write(1, &f, 2);
}
