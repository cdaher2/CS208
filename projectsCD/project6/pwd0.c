//pwd0.c
//an alternate version of pwd written in c
//Christian Daher 10/16/17

#include <stdio.h>
#include <dirent.h>

int c;
char* name = "something went wrong";

int main(int argc, char** argv) {

	struct dirent* d;
	DIR* cd;

	cd = opendir(".");

	while (d = readdir(cd)) {
		if (strcmp(d->d_name, ".") == 0) {
			c = d->d_ino;
			break;
		}
	}

	closedir(cd);

	cd = opendir("..");

	while(d = readdir(cd)) {
		if (d->d_ino == c) {
			name = d->d_name;
			break;
		}
	}

	printf("%s\n", name);
}
