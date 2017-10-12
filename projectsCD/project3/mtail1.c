//mtail1.c
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
	reps = 10;
	ops = 1;
	while ((c = getopt(argc, argv, "nc")) > 0) {
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
				write (1, "invalid option\n", 15);
				return -1;
			default:
				reps = 10;
				ops = 1;
				break;
		}
	}
	while (optind < argc){
		i = 1;
		filename = argv[optind];
		file = open(filename, O_RDONLY);
		if (file >= 0) {
			if (ops == 1) {
				lseek(file, -1, SEEK_END);
				read(file, &buffer, 1);
				while (i <= reps && lseek(file, -2, SEEK_CUR)) {
					read(file, &buffer, 1);
					if (buffer == '\n'){
						i++;
					}
				}
			}
			else if (ops == 2) {
				filename = argv[optind];
				file = open(filename, O_RDONLY);
				lseek(file, reps * -1, SEEK_END);
			}
			while (read(file, &buffer, 1)){
				write (1, &buffer, 1);
			}
			close(file);
		}
		else {
			write (1, "no such file\n", 13);
		}
		write (1, "\n", 1); 
		optind++;
	}
	return 0;
}
