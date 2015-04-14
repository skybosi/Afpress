#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/music", "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	int in = 0, out = 0, len = 0, clen = 0, left = 0;
	fpo = fopen("../test/music.f3", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
	//	printf("%d ", in);
		int canc = 0, len = 0;
		canc = canc_list[in];
		in = in & meta_cans[canc] | head7[canc];
		in |= left << addlen7[canc];
		len = addlen7[canc] + clen;
		if (len >= 8)
		{
			clen = len - 8;
			left = ((1 << clen) - 1) & in;
			out = (in >> clen);
			// printf("\n%3d ", out);
			fputc(out, fpo);
			if (clen >= 8)
			{
				clen -= 8;
				out = (left >> clen);
				left &= ((1 << clen) - 1);
				// printf("\n%3d ", out);
				fputc(out, fpo);
			}
		}
		else
		{
			clen = len;
			left = in;
		}
		in = fgetc(fpi);
	//	getch();
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