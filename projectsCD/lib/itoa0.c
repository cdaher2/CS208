//itoa0.c translates an integer to a string; inverse of atoi

int printf(char* format, ...);
void *calloc(long items, long size);

char* itoa(int number, int field_len);
char charac(int num);

//int main(void) {
//	printf("%s\n", itoa(123,6));
//	printf("%s\n", itoa(1523,6));
//}

char* itoa(int number, int field_len){
	int count = 0;
	int num = number;
	while(num > 0) { //counts the numerals in a number
		num = num/10;
		count++;
	}

	int power = 1;
	int i;
	for(i = 0; i < count; i++) {
		power *= 10;
	}

	char* ascii_num = (char*)calloc(field_len + 1, sizeof(char)); //allocates memory

	for(i = 0; i < field_len; i++) { //puts space and final zero into string
		ascii_num[i] = ' ';
	}
	ascii_num[field_len] = '\0';

	int numeral;
	num = number; 
	while(num > 0) { //finds and inserts numeral characters into the string
		numeral = num/power;
		ascii_num[field_len - count] = charac(numeral);
		count--;
		num = num % power;
		power /= 10;
	}
	return ascii_num;
}

char charac(int num) { 
	return (char) (num + '0');
}
