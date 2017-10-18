//pwd1.c
//an alternate version of pwd written in c
//Christian Daher 10/16/17

#include <stdio.h>
#include <dirent.h>

int c;
char* name = "";

char* buildthestring(char* part, char* orig);

int main(int argc, char** argv) {

	struct dirent* d;
	int f;
	DIR* cd;

	int a = 0;
	while (a == 0) {

		cd = opendir(".");

		while (d = readdir(cd)) {
			f = d->d_ino;
			if (strcmp(d->d_name, ".") == 0) {
				c = d->d_ino;
				break;
			}
		}
		printf("%d, %d, %s\n", f, (int)d->d_ino, d->d_name);
		closedir(cd);

		cd = opendir("..");

		while(d = readdir(cd)) {
			printf("%d, %d, %s\n", f, (int)d->d_ino, d->d_name);
			if (d->d_ino == c) {
				name = buildthestring(d->d_name, name);
				break;
			}
			if (strcmp(d->d_name, "..") == 0) {
				if (f == d->d_ino){
					a = 1;
					break;
				}
			}
		}
		closedir(cd);
		chdir("..");
	}
	printf("%s\n", name);
}

char* buildthestring(char* part, char* orig) {
	char* buffer;
	asprintf(&buffer, "/%s%s", part, orig);
	return buffer;
}
