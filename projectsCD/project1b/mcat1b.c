//mcat1b.c
//an alternate version of cat with the -n option
//Christian Daher 9/13/17

char buffer;

int main(int argc, char** argv) {
	if (open(argv[1], 0000)){
		char i = '1';
		write(1, &i, sizeof(i));
		write(1, " ", 1);
		while (read(3, &buffer, 1)){
			write (1, &buffer, 1);
			if (buffer == '\n') {
				i = i + 1;
				write(1, &i, sizeof(i));
				write(1, " ", 1);
			}
		}
		write (1, '\n', 1);
		close (3);
		return 0;
	}
	else {
		write(2, "Failed to open file. Please try again.\n", 41);
		return -1;
	}
}
