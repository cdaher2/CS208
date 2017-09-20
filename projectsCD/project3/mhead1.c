//mhead1.c
//an alternate version of head written in c
//Christian Daher 9/18/17

#define O_RDONLY 0000
extern int optind;

char buffer;
int file;
int ops;
int reps;
char* filename;

int main(int argc, char** argv){
	while((ops = getopt(argc, argv, "nc:")) != -1) {
		switch (ops) {
			case 'n':
				reps = atoi(argv[optind]);
				ops = 1;
				break;
			case 'c':
				reps = atoi(argv[optind]);
				ops = 2;
				break;
		}
	}

	filename = argv[optind];
	write(1, filename, 5);

	file = open(filename, O_RDONLY);
	int i = 0;
	while (i < reps) {
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
