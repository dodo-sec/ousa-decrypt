#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE* ptr;
	FILE* dec;
	int index, input_c, output_c, magic, key;
	int opt_flag = 0;

	//check for optional flag
	if (argv[1][0] == '-') {
		switch (argv[1][1]) {
		case 'm':	//specifies value for key generation
			opt_flag = 1;
			break;
		case 'h':	//prints usage
			argc = 0;
			break;
		default:
			printf("illegal option %c\n", argv[1][1]);
			break;
		}
	}
	
	if (argc < 3 || argc > 5) {
		printf("%s", "Usage: ousa-decrypt {optional flag} [ENCRYPTED FILE] [OUTPUT FILE]\n\n");
		printf("%s\t%s", "-h", "show this help menu\n");
		printf("%s\t%s", "-m", "magic value for key generation (default is 0x161a)\n");
		return;
	}

	if (opt_flag > 0) {
		magic = strtol(argv[2], NULL, 16);	//assign magic from user input
		ptr = fopen(argv[3], "rb");
		if (ptr == NULL) {
			printf("%s", "Can't open input file\n");
			return;
		}
		dec = fopen(argv[4], "wb");
		if (dec == NULL) {
			printf("%s", "Can't open output file\n");
			return;
		}
	}

	else {
		magic = 0x161a;
		ptr = fopen(argv[1], "rb");
		if (ptr == NULL) {
			printf("%s", "Can't open input file\n");
			return;
		}
		dec = fopen(argv[2], "wb");
		if (dec == NULL) {
			printf("%s", "Can't open output file\n");
			return;
		}
	}

	for (index = 0; (input_c = fgetc(ptr)) != EOF; ++index) {
		key = magic >> index;
		key = ~key;
		output_c = input_c ^ key;
		fputc(output_c, dec);
	}
	fclose(ptr);
	fclose(dec);

	return;
}
