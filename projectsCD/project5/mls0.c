//a version of ls written in c
//Christian Daher 10/2/17
#include <dirent.h>
#define NULL (void *)0

size_t strlen(const char *s);

int main(int argc, char** argv) {
	struct dirent* buffer;
	DIR* cd;

	cd = opendir(".");

	while(buffer = readdir(cd)) {
		write (1, buffer->d_name, strlen(buffer->d_name));
		write (1, "\n", 1);
	}
	return 0;
}
