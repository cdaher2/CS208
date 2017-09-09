/* savedletter.c
* Christian Daher	September 6, 2017
* overwrites a file user input
*/

int main(int argc, char** args) {
	char buffer;

	open(args[1],0101,0600);
	while(read(0,&buffer,1)){
		write(3,&buffer,1);
	}
	close(3);
}
