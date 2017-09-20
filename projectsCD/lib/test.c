#include "cs212lib.h"

int main(void) {
	char* f = itoa(230, 3);
	write(1, f, 3);
}
