//mls1.c
//a version of ls with the -l option available
//Christian Daher 10/11/17

#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#define O_RDONLY 0000
extern int optind;

size_t strlen(const char *s);
int c, ops;


int main(int argc, char** argv){

	struct stat buffer2;
	struct dirent* buffer;
	DIR* cd;

	cd = opendir(".");

	while((c = getopt(argc, argv, "l")) > 0) {
		switch (c) {
			case 'l':
				ops = 1;
				break;
			default:
				ops = 0;
				break;
		}
	}
	switch (ops) {
		case 0:
			while (buffer = readdir(cd)) {
				write (1, buffer->d_name, strlen(buffer->d_name));
				write (1, "\n", 1);
			}
			break;
		case 1:
			while (stat(".", &buffer2)) {
				printf("%o %d  \n", buffer2.st_mode, 
				buffer2.st_uid);//, buffer2.st_gid, buffer2.st_size, 
				//buffer2.st_nlink, buffer2.st_mtime, buffer2.st_atime, 
				//buffer2.st_ctime);
				printf("%s", buffer->d_name);
			}
			break;
	}

	return 0;

}
