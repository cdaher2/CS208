//itoa.c
//itoa function for cs212lib

void *calloc(long items, long size);

char* itoa(int number, int field_len);
char charac(int num);

char* itoa (int number, int field_len) {
	int count = 0;
	int num = number;
	while (num > 0) { //counts the numerals in number
		num = num / 10;
		++count;
	}

	int power = 1;
	int i;
	for (i = 1; i < count; ++i) { //constructs leading power: 10^(count-1)
		power *= 10;
	}

	char* ascii_num = (char*) calloc(field_len + 1, sizeof(char)); // allocates memory

	for (i = 0; i < field_len; ++i) { //puts space and final zero into string
		ascii_num[i] = ' ';
	}
	ascii_num[field_len] = '\0';

	int numeral;
	num = number;
	while (num > 0){ //finds and inserts numeral characters into string
		numeral = num/power;
		ascii_num[field_len - count] = charac(numeral);
		count--;
		num = num % power;
		power /= 10;
	}
	return ascii_num;
}

char charac(int num){
	return (char)(num + '0');
}

