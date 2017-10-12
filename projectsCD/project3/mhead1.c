//mhead1.c
//an alternate version of head written in c
//Christian Daher 9/18/17

#define O_RDONLY 0000
extern int optind;

char buffer;
int file, ops, reps, c, i;
char* filename;

int main(int argc, char** argv){
	ops = 1;
	reps = 10;
	while ((c = getopt(argc, argv, "nc")) > 0) {
		switch (c) {
			case 'n':
				reps = atoi(argv[optind]);
				++optind;
				ops = 1;
				break;
			case 'c':
				reps = atoi(argv[optind]);
				++optind;
				ops = 2;
				break;
			case '?':
				write(2, "invalid option\n", 15);
				return -1;
			default:
				ops = 1;
				reps = 10;
				break;
		}
	}
	while (optind < argc) {
		i = 0;
		filename = argv[optind];
		file = open(filename, O_RDONLY);
		if (file >= 0 ) {
			if (ops == 1){
				while (i <= reps && read(file, &buffer, 1)) {
					write(1, &buffer, 1);
					if (buffer == '\n') {
						++i;
					}
				}
			}
			else if (ops == 2) {
				while (i < reps && read(file, &buffer, 1)) {
					write(1, &buffer, 1);
					++i;
				}
			}
			close(file);
		}
		else {
			write (1, "no such file\n", 13);
		}
		write(1, "\n", 1);
		++optind;
	}
	return 0;
}
