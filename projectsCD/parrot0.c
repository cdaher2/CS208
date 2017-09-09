/* parrot0.c
*Christian Daher; September 6, 2017
*The program should print the first letter entered by the user
*/
int main(void){
	char buffer;

	read(0,&buffer,1);
	write(1,&buffer,1);
}
