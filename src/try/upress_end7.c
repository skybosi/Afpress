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
	int in = 0, in2 = 0, out = 0, in2 = 0, clen = 0, left = 0, left2 = 0, key =
		0;
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
		// gethead >> getcanc
		if (key == 0)
		{
			while ((gethead7[++canc] & (in >> (len - 6))) != matchead7[canc]);
			if (canc > 5)
				key = 1;
		}
		else
		{
			while ((gethead70[++canc] & (in >> (len - 7))) !=
				   matchead70[canc]);
			addlen7[canc] = 8;
			left2 = ((1 << clen) - 1) & in;
			in2 = fgetc(fpi);
			fseek(fpi, -1, 1);
			left2 <<= 8;
			in2 |= left2;
			int canc2 = -1 ;
			while ((gethead70[++canc2] & (in >> (len - 7))) !=
				   matchead70[canc2]);
			if (canc2 < 6)
				key = 0;
		}
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
			// printf("%d ", out);
			fputc(out, fpo);
			if (clen >= 7)
			{
				/* if (clen == 7) { left <<= 1; clen++; } */// 该句可能会导致程序bug
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
					// printf("%d ", out);
					fputc(out, fpo);
				}

			}
		}
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