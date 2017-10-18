//pwd1.c //an alternate version of pwd written in c //Christian Daher 10/16/17

#include <stdio.h>
#include <dirent.h>

int c, f;
char* name = "";

char* buildthestring(char* part, char* orig);

int main(int argc, char** argv) {

	struct dirent* d;
	DIR* cd;

	int a = 0;
	while (a == 0) {

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
				if (strcmp(d->d_name, "..") == 0){
					a = 1;
					break;
				}
				else {
					name = buildthestring(d->d_name, name);
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
