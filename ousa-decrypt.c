#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE* ptr;
	FILE* dec;
	int c, index, input_c, output_c, key;
	int magic = 0x161a;
	
	//check for presence of optional flags;
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c)
			{
			case 'h':
				argc = 0;
				break;
			case 'm':
				magic = strtol(*++argv, NULL, 16);	//converts user input magic to int hex;
				printf("Using magic %x\n", magic);
				break;
			default:
				break;
			}
	
	if (argc != 3) {	//checks for correct amount of remaining arguments after counting optional flags;
		printf("%s", "Usage: ousa-decrypt {optional flag} [ENCRYPTED FILE] [OUTPUT FILE]\n\n");
		printf("%s\t%s", "-h", "show this help menu\n");
		printf("%s\t%s", "-m", "magic value for key generation (default is 0x161a)\n");
		return;
	}

	ptr = fopen(*argv++, "rb");	//increments argv after use to point to output file for next open operation;
	if (ptr == NULL) {
		printf("%s", "Can't open input file\n");
		return;
	}
	
	dec = fopen(*argv, "wb");
	if (dec == NULL) {
		printf("%s", "Can't open output file\n");
		return;
	}

	for (index = 0; (input_c = fgetc(ptr)) != EOF; ++index) {
		key = magic >> index;
		key = ~key;
		output_c = input_c ^ key;
		fputc(output_c, dec);
	}
	printf("%s", "Done writing output file\n");
	fclose(ptr);
	fclose(dec);

	return;
}
