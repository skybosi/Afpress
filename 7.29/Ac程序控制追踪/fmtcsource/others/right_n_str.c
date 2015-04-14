// #include"fmt_c_code.h"
char *right_n_str(char *dst, const char *src, int n)
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len)
		n = len;
	p += (len - n);				// 从右边第n个字符开始
	while (*(q++) = *(p++));
	return dst;
}

