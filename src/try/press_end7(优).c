#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/picture", "rb");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	char ch = 0;
	int in = 0, in2 = 0, canc = 0, canc2 = 0, len = 0, clen =
		0, key = 1, left = 0;
	fpo = fopen("../test/picture.f0", "wb");
	system("date");
	in = fgetc(fpi);
	// printf("%d ",key);
	while (!feof(fpi))
	{
		// printf("%3d ",in);
		canc = canc_list[in];
		// 锁机制处理段
		if (key == 0)
		{
			in = (in & meta_cans[canc]) | head7[canc];
			in |= left << addlen7[canc];
			len = addlen7[canc] + clen;
			key = 1;
		}
		else
		{
			in = (in & meta_cans[canc]) | head70[canc];
			in |= left << 8;
			len = 8 + clen;
			in2 = fgetc(fpi);
			canc2 = canc_list[in2];
			fseek(fpi, -1, 1);
			if (canc2 < 6)
				key = 0;
		}
		// 裂解大数
		clen = len % 8;
		left = ((1 << clen) - 1) & in;
		len /= 8;
		while (len--)
		{
			ch = in >> (len * 8 + clen) & 0xff;
			fputc(ch, fpo);
			// printf("[%-3d]\n",ch);
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