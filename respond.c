#include <stdio.h>
#include <string.h>

const char string[] = "Edit: Also, if you are reading this, you are probably wasting your time just decoding some random comment on reddit LMAO.";

int main(int argc, char *argv[]) {
	int string_length = strlen(string);
	
	for (int i = 0; i < string_length; i++) {
		printf("%x ", string[i]);
	}
	
	putchar('\n');
	
	return 0;
}
