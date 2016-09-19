#include <stdio.h>
#include <conio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main()
{
	int flen;
	char *str;
	FILE *fp = fopen("test.txt", "rb");

	if (fp == NULL) {
		fprintf(stderr,"Error: %s", strerror(errno));
		_getch();
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	flen = ftell(fp);
	printf("File Size: %d\n", flen);
	fseek(fp, 0L, SEEK_SET);
	str = (char *)calloc(flen + 1, sizeof(char));
	printf("Read Size: %d\n", fread(str, flen, sizeof(char), fp));
	str[flen] = 0x00;
	printf("%s\n", str);
	free(str);
	str = NULL;
	fclose(fp);
	fp = NULL;
	_getch();
	return 0;
}