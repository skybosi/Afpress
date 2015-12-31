#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/zhtxt", "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	char ch = 0;
	int in = 0, canc = 0, len = 0, clen = 0, left = 0;
	fpo = fopen("../test/zhtxt.f7", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
		// printf("%d ", in);
		canc = canc_list[in];
		in = in & meta_cans[canc] | head7[canc];
		in |= left << addlen7[canc];
		len = addlen7[canc] + clen;
		// 裂解大数
		clen = len % 8;
		left = ((1 << clen) - 1) & in;
		len /= 8;
		while (len--)
		{
			ch = in >> (len * 8 + clen) & 0xff;
			fputc(ch, fpo);
		}
		in = fgetc(fpi);
		// getch();
	}
	if (clen)
	{
		printf("%d %d", clen, left);
		fputc(left, fpo);
	}
	fclose(fpi);
	fclose(fpo);
	system("date");
	fpi = fpo = NULL;
	return 0;
}
