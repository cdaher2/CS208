int strcmp(const char *s, const char *f);

char* l;
char* t;


int main(void) {
	l = "-fish";
	t = "fish";
	int g = strcmp(l, t);
	write (1, g, 1);
	return 0;
}
