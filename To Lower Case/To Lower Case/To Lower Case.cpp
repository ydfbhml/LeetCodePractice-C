#include <stdio.h>

char * toLowerCase(char * str) {
	char * head = str;

	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z') {
			*str = *str + 'a' - 'A';
		}
		str++;
	}
	return head;
}

int main() {
	char input[] = "PiTAs";
//	char input[] = "HELLO";
	char* str = input;

	char* output = toLowerCase(str);
	printf("%s", output);

	return 0;
}