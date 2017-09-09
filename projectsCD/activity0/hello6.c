#define STDOUT 1

int strlen(char* text);

int main() {
	char* message = "System Call!\n";
	int char_count = strlen(message);
	write(STDOUT, message, char_count);
	return 0;
}

int strlen(char* text) {
	int i;
	for (i = 0; text[i]; i = i + 1) {}
	return i;
}
