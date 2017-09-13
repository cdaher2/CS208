//initialized.c
//prints the value of an uninitialized local variable

int printf(const char *format, ...);

int main(void) {
	int i;
	printf(" i has the  value %d\n", i);
	return 0;
}
