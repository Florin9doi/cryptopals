#include <stdio.h>
#include <stdint.h>

/*
	echo -n 49276d206b696c6 | challenge1
*/

int main(int argc, char **argv) {

	char lookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					"abcdefghijklmnopqrstuvwxyz"
					"0123456789+/";

	uint8_t index = 0;
	uint8_t rest = 0;

	int8_t buffer;
	while ((buffer = getchar()) != EOF) {
		uint8_t hexByte = 0;
		if (buffer >= '0' && buffer <= '9') {
			hexByte = buffer - '0';
		} else if (buffer >= 'a' && buffer <= 'f') {
			hexByte = 10 + buffer - 'a';
		} else if (buffer >= 'A' && buffer <= 'F') {
			hexByte = 10 + buffer - 'A';
		}

		uint8_t cval = 0;
		if (index == 0) {
			rest = hexByte;
			index = 1;
			continue;
		} else if (index == 1) {
			cval = rest << 2 | hexByte >> 2;
			rest = hexByte & 0x3;
			index = 2;
		} else if (index == 2) {
			cval = rest << 4 | hexByte;
			rest = 0;
			index = 0;
		}
		printf("%c", lookup[cval]);
	}
	return 0;
}