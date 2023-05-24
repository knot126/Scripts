#include <stdio.h>
#include <string.h>

const char string[] = "01011001 01101111 01110101 00100000 01100001 01110010 01100101 00100000 01100001 00100000 01101110 01100101 01110010 01100100 00100000 01111001 01100110 00100000 01111001 01101111 01110101 00100000 01100011 01100001 01101110 00100000 01110010 01100101 01100001 01100100 00100000 01110100 01101000 01101001 01110011";

int main(int argc, char *argv[]) {
	int string_length = strlen(string);
	int power = 0;
	int value = 0;
	
	for (int i = 0; i <= string_length; i++) {
		power++;
		
		switch (string[i]) {
			case '1':
				value |= (1 << (8 - power));
				break;
			case '0':
				break;
			default:
				if (value) putchar(value);
				value = 0;
				power = 0;
				break;
		}
	}
	
	putchar('\n');
	
	return 0;
}
