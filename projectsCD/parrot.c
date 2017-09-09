/* parrot.c
*Christian Daher; September 6, 2017
*The program should print the first letter entered by the user
*/


char buffer;

int main(void){
	while(read(0,&buffer,1)){
		write(1,&buffer,1);
	}
}
