//mtail0.c
//an alternate version of tail written in c
//Christian Daher 9/24/2017
#define O_RDONLY 0000

char buffer;

int main(int argc, char** argv) {
	int file = open(argv[1], O_RDONLY);
	int i = 0;
	while (read (file, &buffer, 1)) {
		if (buffer == \n) {
			++i;
		}
	}
	int i2 = i - 10;
	
	while (i2 < i) {
		read(file, &buffer, 1
