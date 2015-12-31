#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/picture.f7", "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	int in = 0, out = 0, clen = 0, left = 0;
	int chose_way = 0;
	fpo = fopen("../test/picture.27", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
		int len = 8, canc = -1;
		len += clen;
		left <<= 8;
		in |= left;
		GETC(len, in, 6);
		if (len >= addlen7[canc])
		{
			clen = len - addlen7[canc];
			left = ((1 << clen) - 1) & in;
			in >>= clen;
			GETO;
			// 过长处理
			if (clen >= 7)
			{
				/* if (clen == 7) { left <<= 1; clen++; } */// 该句可能会导致程序bug
				int canc = -1;
				GETC(clen, left, 6);
				if (clen >= addlen7[canc])
				{
					clen -= addlen7[canc];
					in = left >> clen;
					left &= ((1 << clen) - 1);
					GETO;
				}
			}
		}
		// 后续处理段
		else
		{
			clen = len;
			left = in;
		}
		// getch();
		in = fgetc(fpi);
	}
	fclose(fpi);
	fclose(fpo);
	system("date");
	fpi = fpo = NULL;
	return 0;
}