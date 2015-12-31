#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/picture", "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	int in = 0, in2 = 0, out = 0, canc = 0, canc2 = 0, len =
		0, clen = 0, key = 0, left = 0;
	fpo = fopen("../test/picture.f7", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
		canc = canc_list[in];
		// 锁机制处理段
		if (key == 0)
		{
			in = in & meta_cans[canc] | head7[canc];
			in |= left << addlen7[canc];
			len = addlen7[canc] + clen;
			// if (canc > 5)
			key = 1;
		}
		else
		{
			in = in & meta_cans[canc] | head70[canc];
			in |= left << 8;
			len = 8 + clen;
			in2 = fgetc(fpi);
			canc2 = canc_list[in2];
			fseek(fpi, -1, 1);
			if (canc2 < 6 )
				key--;
		}
		// 输出处理段
		if (len >= 8)
		{
			clen = len - 8;
			left = ((1 << clen) - 1) & in;
			out = (in >> clen);
			fputc(out, fpo);
			if (clen >= 8)
			{
				clen -= 8;
				out = (left >> clen);
				left &= ((1 << clen) - 1);
				fputc(out, fpo);
			}
		}
		// 后续处理段
		else
		{
			clen = len;
			left = in;
		}
		in = fgetc(fpi);
		// getch();
	}
	if (clen)
	{
		// printf("%d %d", clen, left);
		fputc(left, fpo);
	}
	fclose(fpi);
	fclose(fpo);
	system("date");
	fpi = fpo = NULL;
	return 0;
}