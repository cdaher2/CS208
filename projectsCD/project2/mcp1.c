
//mcp1.c
//an alternate version of cp written in c
//Christian Daher 9/13/17

#include <fcntl.h>

char buffer;


int main(int argc, char** argv) {
	open(argv[1], O_RDONLY);
	open(argv[2], O_WRONLY | O_CREAT, 0600);
	while (read(3, &buffer, 1)){
		write(4, &buffer, 1);
		write(1, &buffer, 1);
	}
	close(3);
	close(4);
	return 0;
}
