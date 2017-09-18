//mhead0.c
//an alternate version of head written in c
//Christian Daher 9/18/17
#define O_RDONLY 0000

char buffer;

int main(int argc, char** argv){
	int file = open(argv[1], O_RDONLY);
	int i = 0;
	while (i < 10) {
		read (file, &buffer, 1);
		write (1, &buffer, 1);
		if (buffer == '\n') {
			i = i + 1;
		}
	}
	write (1, '\n', 1);
	close(file);
	return 0;
}
