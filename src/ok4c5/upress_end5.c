#include"fqpress3.h"
int main(int argc, char *argv[])
{
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen("../test/music.f5", "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	int in = 0, out = 0, in2 = 0, clen = 0, left = 0;
	int chose_way = 0;
	fpo = fopen("../test/music.25", "w");
	system("date");
	in = fgetc(fpi);
	while (!feof(fpi))
	{
		int len = 8, canc = -1;
		len += clen;
		left <<= 8;
		in |= left;
		// gethead >> getcanc
		while ((gethead7[++canc] & (in >> (len - 6))) != matchead7[canc]);
		if (len >= addlen7[canc])
		{
			clen = len - addlen7[canc];
			left = ((1 << clen) - 1) & in;
			in >>= clen;
			out = in & meta_cans[canc];
			chose_way = chose_wayl7[canc] & out;
			if (canc == 0)
				chose_way = !chose_way;
			if (!chose_way)
				out |= (0xff >> canc << canc);
		//	printf("%d ", out);
			fputc(out, fpo);
			if (clen >= 7)
			{
				int canc = -1;
				while ((gethead7[++canc] & (left >> (clen - 6))) !=
					   matchead7[canc]);
				if (clen >= addlen7[canc])
				{
					clen -= addlen7[canc];
					in = left >> clen;
					left &= ((1 << clen) - 1);
					out = in & meta_cans[canc];
					chose_way = chose_wayl7[canc] & out;
					if (canc == 0)
						chose_way = !chose_way;
					if (!chose_way)
						out |= (0xff >> canc << canc);
				//	printf("%d ", out);
					fputc(out, fpo);
				}

			}
		}
		else
		{
			clen = len;
			left = in;
		}
	//	getch();
		in = fgetc(fpi);
		
	}
	fclose(fpi);
	fclose(fpo);
	system("date");
	fpi = fpo = NULL;
	return 0;
}