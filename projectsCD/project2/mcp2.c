
//mcp1.c
//an alternate version of cp written in c
//Christian Daher 9/13/17

#include <fcntl.h>

char buffer[100000];


int main(int argc, char** argv) {
	open(argv[1], 0000);
	open(argv[2], 0101, 0600);
	while (read(3, &buffer, 100000)){
		write(4, &buffer, 100000);
	}
	close(3);
	close(4);
	return 0;
}
