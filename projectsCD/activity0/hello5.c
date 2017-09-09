#define STDOUT 1

int strlen(char* text);

int main() {
	char* message = "System Call!\n";
	int char_count = strlen(message);
	write (STDOUT, message, char_count);
	return 0;
}
