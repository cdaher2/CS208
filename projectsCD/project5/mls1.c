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

	while((c = getopt(argc, argv, "l")) != -1) {
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
				printf("%s \n", buffer->d_name);
			}
			break;
		case 1:
			while (buffer = readdir(cd)) {
				stat(buffer->d_name, &buffer2);
				printf("%s\n", buffer->d_name);
				printf("Mode: %lo Link count: %ld Ownership:UID:%ld GID:%ld Filesize: %ld\n Last modified: %s Last accessed: %s Last status change: %s \n", 
				(unsigned long)buffer2.st_mode, (long)buffer2.st_nlink,
				(long)buffer2.st_uid, (long)buffer2.st_gid, (long)buffer2.st_size, 
				ctime(&buffer2.st_mtime), ctime(&buffer2.st_atime), 
				ctime(&buffer2.st_ctime));
				printf("\n");
			}
			write (1, "\n", 1);
			break;
	}

	return 0;

}
