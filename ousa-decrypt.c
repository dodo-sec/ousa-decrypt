#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE* ptr;
	FILE* dec;
	int c;
	int nc;
	int d;
	int key;

	if (argc != 3) {
		printf("% s", "Usage: ousa-decrypt-v3 [encrypted file] [output file]\n");
		exit();
	}

	ptr = fopen(argv[1], "rb");
	if (ptr == NULL) {
		printf("%s", "Can't open input file\n");
		exit();
	}
	dec = fopen(argv[2], "wb");
	if (dec == NULL) {
		printf("%s", "Can't open output file\n");
		exit();
	}

	for (nc = 0; (c = fgetc(ptr)) != EOF; ++nc) {
		key = 0x161a >> nc;
		key = ~ key;
		d = c ^ key;
		fputc(d, dec);
	}
	fclose(ptr);
	fclose(dec);
}