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
	int in = 0, in2 = 0, out = 0, len = 0, clen = 0, key = 0, left = 0;
	fpo = fopen("../test/picture.f77", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
		// printf("%d ", in);
		int canc = 0, len = 0;
		canc = canc_list[in];
		printf("\n%d ",canc);
		getbitlist(in);
		if (key == 0)
		{
			in = in & meta_cans[canc] | head7[canc];
		//	printf("newin=%d ", in);
			getbitlist(in);
			in |= left << addlen7[canc];
			len = addlen7[canc] + clen;
		//	printf("len=%d ", len);
		//	if (canc == 6 || canc == 7)
				key = 1;
		}
		else
		{
			in = in & meta_cans[canc] | head71[canc];
		//	printf("5newin=%d ", in);
			getbitlist(in);
			in |= left << 8;
			len = 8 + clen;
		//	printf("len=%d ", len);
			int canc2 = 0;
			in2 = fgetc(fpi);
		//	printf("in2=%d ",in2);
			canc2 = canc_list[in2];
			fseek(fpi, -1, 1);
			if (canc2 < 6)
				key = 0;
		}
		printf("%d ", key);
		if (len >= 8)
		{
			clen = len - 8;
			left = ((1 << clen) - 1) & in;
			out = (in >> clen);
			// printf("\n%3d ", out);
		//	printf("\n\tggg1♥♥♥♥♥♥out=%3d ", out);
			getbitlist(out);
		//	printf("\n");
			fputc(out, fpo);
			if (clen >= 8)
			{
				clen -= 8;
				out = (left >> clen);
				left &= ((1 << clen) - 1);
			//	printf("\n\tggg2♥♥♥♥♥♥out=%3d ", out);
				getbitlist(out);
			//	printf("\n");
				fputc(out, fpo);
			}
		}
		else
		{
			clen = len;
			left = in;
		}
	//	printf("clen=%d left=%3d ", clen, left);
		getbitlist(left);
		in = fgetc(fpi);
		//getch();
	}
	if (clen)
	{
	//	printf("%d %d", clen, left);
		fputc(left, fpo);
	}
	fclose(fpi);
	fclose(fpo);
	system("date");
	printf("ok");
	fpi = fpo = NULL;
	return 0;
}

void getbitlist(int n)
{
	int bits[8] = { 0 };
	int bit[] = { 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1 };
	for (int i = 0; i < 8; i++)
	{
		bits[i] = (n & bit[i]) / bit[i];
		//printf("%d", bits[i]);
	}
	//printf("  ");
} 