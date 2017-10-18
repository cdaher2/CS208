/* fork0.c  */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
	printf ("before fork: program process ID is %d\n", (int) getpid ());
	fork();
	printf ("after fork: program process ID is %d\n", (int) getpid ());
}
