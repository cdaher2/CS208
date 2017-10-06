//mtail0.c
//an alternate version of tail written in c
//Christian Daher 9/24/2017
#include <sys/types.h>
#define O_RDONLY 0000
#define SEEK_CUR 1
#define SEEK_END 2

off_t lseek(int fd, off_t offset, int whence);
char buffer;

int main(int argc, char** argv) {
	int file = open(argv[1], O_RDONLY);
	int i = 0;
	lseek(file, -1, SEEK_END);
	while (i <= 10) {
		read(file, &buffer, 1);
		lseek(file, -2, SEEK_CUR);
		if (buffer == '\n'){
			i++;
		}
	}
	read(file, &buffer, 2);
	while (read(file, &buffer, 1)){
		write (1, &buffer, 1);
	}
	return 0;
}
