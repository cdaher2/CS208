//mcat.c
//an alternate version of cat
//Christian Daher 9/11/17

char buffer;
int file;

int main(int argc, char** argv) {
	file = open(argv[1], 0000);
	while (read(file, &buffer, 1)) {
		write(1, &buffer, 1);
	}
	close(file);
	return 0;
}
