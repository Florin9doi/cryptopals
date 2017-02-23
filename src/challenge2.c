#include<stdio.h>
#include<inttypes.h>

/*
	./challenge2 1c0111001f010100061a024b53535009181c 686974207468652062756c6c277320657965
*/

uint8_t char_to_hex(uint8_t in) {
	if(in >= '0' && in <= '9') {
		return in - '0';
	} else if (in >= 'a' && in <= 'z') {
		return 10 + in - 'a';
	} else if (in >= 'A' && in <= 'Z') {
		return 10 + in - 'A';
	}
	return 0;
}

char int_to_hex(uint8_t in) {
	char lookup[] = "0123456789abcdef";
	return lookup[in];
}

int main (int argc, char **argv) {
	if (argc != 3) {
		printf("%s param1 param2\n", argv[0]);
		return 1;
	}
	char *s1 = argv[1];
	char *s2 = argv[2];
	int i = 0;
	for (i = 0; s1[i] && s2[i]; i++) {
		uint8_t val = char_to_hex(s1[i]) ^ char_to_hex(s2[i]); 
		printf("%c", int_to_hex(val));
	}
}