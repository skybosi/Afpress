#include"../include/fmt_c_code.h"
void del_blank_line(char *str)
{
	char *tmp=str;
	while ((*str == ' ') || (*str == '\t'))
		str++;
	while (*(tmp++) = *(str++));
}