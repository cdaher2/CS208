//mcat.c
//an alternate version of cat
//Christian Daher 9/11/17

char buffer = 'F';

int main(int argc, char** argv) {
	int file = open(argv[1]);
	int i;
	write(1, &buffer, 1);
	while (read(file, &buffer, 1) != -1) {
		write(1, &buffer, 1);
	}
	write(1, &buffer, 1);
	return 0;
}
