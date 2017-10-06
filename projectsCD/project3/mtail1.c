//mtail0.c
//an alternate version of tail written in c
//Christian Daher 9/24/2017
#include <sys/types.h>
#define O_RDONLY 0000
#define SEEK_CUR 1
#define SEEK_END 2

off_t lseek(int fd, off_t offset, int whence);
extern int optind;

char buffer;
int file, ops, reps, c, i;
char* filename;

int main(int argc, char** argv) {
	while (c = getopt(argc, argv, "nc")) {
		switch(c) {
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
				reps = 10;
				ops = 1;
				break;
		}
		i = 0;
		switch(ops){
			case 1:
				filename = argv[optind];
				file = open(filename, O_RDONLY);
				lseek(file, -1, SEEK_END);
				while (i <= reps) {
					read(file, &buffer, 1);
					lseek(file, -2, SEEK_CUR);
					if (buffer == '\n'){
						i++;
					}
				}
				break;
			case 2:
				filename = argv[optind];
				file = open(filename, O_RDONLY);
				lseek(file, reps * -1, SEEK_END);
				break;
		}


		read(file, &buffer, 2);
		while (read(file, &buffer, 1)){
			write (1, &buffer, 1);
		}
		optind++;
	}
	return 0;
}
