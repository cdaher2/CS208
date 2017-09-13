//mcat1.c
//an alternate version of cat with the -n option
//Christian Daher 9/13/17
#include <fcntl.h>

char buffer;

int main(int argc, char** argv) {
	int file = open(argv[1], O_RDONLY);
	char i = '0';
	write(1, &i, sizeof(i));
	write(1, " ", 1);
	while (read(file, &buffer, 1)){
		write (1, &buffer, 1);
		if (buffer == '\n') {
			i = i + 1;
			write(1, &i, sizeof(i));
			write(1, " ", 1);
		}
	}
	write (1, '\n', 1);
	close (file);
	return 0;
}
