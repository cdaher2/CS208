//mcat.c
//an alternate version of cat
//Christian Daher 9/11/17
#include <fcntl.h>

char buffer;

int main(int argc, char** argv) {
	int file = open(argv[1], O_RDONLY);
	while (read(file, &buffer, 1)) {
		write(1, &buffer, 1);
	}
	return 0;
}
