/*
	__dumb lang__
	Author: Hamza Albanna
	Version: beta
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef char *string;

int main(int argc, string argv[]) {
	if (argc != 2) {
		printf("\033[0;31mError: you did not specify the file you want to compile\033[0m\n");
		return 1;
	}

	if (strcmp(argv[1], "docs") == 0) {
		printf("In dumb you have an array of length 10,000\n");
		printf(">: shift right\n");
		printf("<: shift left\n");
		printf("+: add 1\n");
		printf("-: subtract 1\n");
		printf("!: print\n");
		printf("c: print as ascii character however the ascii table will start at 32 instead of zero,\n");
		printf("   which in this language 0 = 32 on the ascii table, EX: 1 = '!'(dumb lang), 33 = '!'(ascii table)\n");
		printf("n: newline\n");
		printf("i: takes input as an integer\n");
		printf(".: to end the program\n");
		return 0;
	} else {
		int16_t arr[3000];
		uint16_t index = 0;
		uint8_t size = strlen(argv[1]);
		char check[6] = ".dumb";
		char t;

		FILE *in = fopen(argv[1], "r");
		if (in == NULL) {
			printf("\033[0;31mError: file does not exist\033[0m\n");
			return 1;
		}

		for (int i = 0; i < 5; i++) {
			if (argv[1][size - 5 + i] != check[i]) {
				printf("\033[0;31mError: incompatible file type, file must end in .dumb\033[0m\n");
				return 1;
			}
		}

		for (int i = 0; i < 3000; i++) arr[i] = 0;

		while (1) {
			fscanf(in, "%c", &t);

			if (t == '+') {
				arr[index]++;
			} else if (t == '-') {
				arr[index]--;
			} else if (t == 'c') {
				printf("%c", arr[index] + 32);
			} else if (t == '!') {
				printf("%i", arr[index]);
			} else if (t == 'n') {
				printf("\n");
			} else if (t == '>') {
				index++;
			} else if (t == '<') {
				index--;
			} else if (t == 'i') {
				scanf("%hi", &arr[index]);
			} else if (t == '.') {
				return 0;
			} else if (t > '0' && t <= '9') {
				arr[index] += (int)t - 48;
			} else if (t == '_') {
				fscanf(in, "%c", &t);
				if (t > '0' && t <= '9') {
					arr[index] -= (int)t - 48;
				} else {
					printf("\033[0;31mError: Invalid operator\033[0m\n");
					return 1;
				}
			}
		}

		fclose(in);
		return 0;
	}

	return 0;
}
