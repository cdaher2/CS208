//mhead1.c
//an alternate version of head written in c
//Christian Daher 9/18/17

#define O_RDONLY 0000
extern int optind;

char buffer;
int file;
int ops;
int reps;
int c;
char* filename;

int main(int argc, char** argv){
	ops = 0;
	c = getopt(argc, argv, "nc:");
	switch (c) {
		case 'n':
			reps = atoi(argv[optind]);
			++optind;
			ops = 1;
			break;
		case 'c':
			--optind;
			reps = atoi(argv[optind]);
			++optind;
			ops = 2;
			break;
		case '?':
			write(2, "invalid option\n", 15);
			return -1;
		default:
			ops = 0;
			break;
	}

	int i = 0;
	switch (ops) {
		case 0:
			filename = argv[1];
			file = open(filename, O_RDONLY);
			while(i < 10) {
				read(file, &buffer, 1);
				write(1, &buffer, 1);
				if (buffer == '\n') {
					++i;
				}
			}
			break;
		case 1:
			filename = argv[optind];
			file = open(filename, O_RDONLY);
			while (i < reps) {
				read (file, &buffer, 1);
				write (1, &buffer, 1);
				if (buffer == '\n') {
					++i;
				}
			}
			break;
		case 2:
			filename = argv[optind];
			file = open(filename, O_RDONLY);
			while (i < reps) {
				read (file, &buffer, 1);
				write (1, &buffer, 1);
				++i;
			}
			if (buffer != '\n') {
				write (1, "\n", 1);
			}
			break;
	}
	close(file);
	return 0;
}
