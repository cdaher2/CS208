//hello2.c
int main() {
	char* message = "System Call!\n";
	write (1, message, 13);
	return 0;
}
