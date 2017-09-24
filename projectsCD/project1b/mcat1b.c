//mcat.c
//an finalized alternate version of cat with the -n option
//Christian Daher 9/13/17

#include "cs212lib.h"
extern int optind;

char buffer;
int file;
int ops, c;
char* filename, f;

int main(int argc, char** argv) {
	ops = 0;
	while ((c = getopt(argc, argv, "n")) > 0) {
		switch(c) {
			case 'n':
				ops = 1;
				break;
			default:
				ops = 0;
				break;
		}
	}
	file = open(argv[optind], 0000);
	int i = 1;
	if (ops == 1) {
		write(1, itoa(i, 5), 5);
		write(1, " ", 1);
	}
	while (read(file, &buffer, 1)){
		write (1, &buffer, 1);
		if (buffer == '\n') {
			i = i + 1;
			if (ops == 1) {
				write(1, itoa(i, 5), 5);
				write(1, " ", 1);
			}
		}
	}
	write (1, "\n", 1);
	close (file);
	return 0;
}
