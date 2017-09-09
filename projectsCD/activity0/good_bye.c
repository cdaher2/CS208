#define STDOUT 1

long strlen(char* text);
int printf(const char* format, ...);

int main() {
	char* message = "That's all for today!";
	long char_count = strlen(message);
	write(STDOUT, message, char_count);
	write(1, "\n", 1);
	printf (" message: %s\n character count: %ld\n STDOUT: %d\n", message, char_count, STDOUT);
	return 0;
}
