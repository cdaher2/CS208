//hello1.c
int main() {
	char* message;
	message = "System Call!\n";
	write (1, message, 13);
	return 0;
}
