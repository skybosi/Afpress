// #include"fmt_c_code.h"
char *left_n_str(char *dst, char *src, int n)
{
	char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len)
		n = len;
	while (n--)
		*(q++) = *(p++);
	 *(q++) = '\0';	/* 有必要吗？很有必要 */
	return dst;
}