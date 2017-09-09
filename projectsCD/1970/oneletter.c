/* oneletter.c
* Christian Daher
*
*opens a file named: aletter and 
*writes the first letter of the file to the screen
*/
int main(void){
	char buffer;

	open("aletter", 0);
	read(3,&buffer,1);
	write(1,&buffer,1);

	close(3);
	return 0;
}
