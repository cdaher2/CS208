#define STDOUT 1

int main() {
	char* message = "System Call!\n";
	int char_count = 13;
	write (STDOUT, message, char_count);
	return 0;
}
