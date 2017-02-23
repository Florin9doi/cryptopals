#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>

/*
	./challenge3 1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
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

uint8_t validate(char *in) {
	int alfanum = 0;
	for (int i = 0; i < strlen(in); i++) {
		if (in[i] < ' ' || in[i] > '~') {
			return 0;
		}
		if ((in[i] >= '0' && in[i] <= '9')
		 || (in[i] >= 'a' && in[i] <= 'z')
		 || (in[i] >= 'A' && in[i] <= 'Z')
		 || in[i] == ' ') {
			alfanum ++;
		}
	}
	return alfanum;
}

int main (int argc, char **argv) {
	if (argc != 2) {
		printf("%s param\n", argv[0]);
		return 1;
	}

	char *s1 = argv[1];
	int i = 0;
	char *message = malloc (strlen(s1)+1);

	for (uint16_t key = 0; key <= 0xFF; key++) {
		memset(message, 0, sizeof(*message));
		for (i = 0; s1[i] && s1[i+1]; i+=2) {
			uint8_t ch = char_to_hex(s1[i]) << 4 | char_to_hex(s1[i+1]);
			message[i/2] = ch ^ key;
		}
		if (validate(message) > ((float)strlen(s1)/2/100*90)) {
			printf("key = %x" "\n" "message = %s\n", key, message);
		}
	}
}