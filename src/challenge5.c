#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>

/*
	./challenge5 5.txt ICE
*/

int main (int argc, char **argv) {
	if (argc != 3) {
		printf("%s file key\n", argv[0]);
		return 1;
	}
	char *key = argv[2];
	uint8_t key_index = 0;
	char ch;
	FILE *file = fopen(argv[1], "rt");

	while (fscanf(file, "%c", (char*)&ch) != EOF) {
		uint8_t ret = ch ^ key[key_index];
		key_index = key[key_index+1] ? key_index+1 : 0;
		printf("%02x", ret);
	}
}