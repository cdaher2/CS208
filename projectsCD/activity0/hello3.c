int main() {
	char* message = "System Call!\n";
	int char_count = 11;
	write (1, message, char_count);
	return 0;
}
