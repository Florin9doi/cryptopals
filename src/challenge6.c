#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>

/*
	./challenge6 'this is a test' 'wokka wokka!!!'
*/

int main (int argc, char **argv) {
	if (argc != 3) {
		printf("%s file key\n", argv[0]);
		return 1;
	}
	char *str1 = argv[1];
	char *str2 = argv[2];
	int distance = 0;

	for(int i=0; str1[i] && str2[i]; i++) {
		uint8_t xor = str1[i] ^ str2[i];
		while (xor) {
			distance += xor & 1;
			xor >>= 1;
		}
	}
	printf("distance = %d\n", distance);
}