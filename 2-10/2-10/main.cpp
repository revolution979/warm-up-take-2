#include <stdio.h>
int main() {
	char string[64];
	printf("What is your full name?\n");
	fgets(string, 64, stdin);
	printf("Hello, %s! Nice to meet you! You are awesome\n", string);
	return 0;

}