//mtail0.c
//an alternate version of tail written in c
//Christian Daher 9/24/2017
#define O_RDONLY 0000

off_t offset = lseek(int f, int_t offset, int from_where);
char buffer;

int main(int argc, char** argv) {
	int file = open(argv[1], O_RDONLY);
	
