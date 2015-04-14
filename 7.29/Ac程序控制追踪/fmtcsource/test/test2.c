#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char **cutstr(char *str, int *pos);
char *substr(char *s, int n1, int n2);
int main()
{
	char **str_each;
	char str[] = "bhjjhdhjdsdfyyg…&&nbbhbjjj";
	int pos[] = { 4, 0, 7, 9, 15, 28 };
	str_each = cutstr(str, pos);
	int i;
	for (i = 0; i < pos[0]; ++i)
	{
		printf("%d %s\n", i,str_each[i]);
		delete str_each[i];
	}
	delete str_each;
	return 0;
}

char **cutstr(char *str, int *pos)
{

	char **str_each = new char *[pos[0]+1];
	int i = 1;
	while (i <= pos[0])
	{
		str_each[i] = new char[pos[i + 1] - pos[i] + 2 ];
		str_each[i - 1] = substr(str, pos[i], pos[i + 1]);
		// printf("%s\n", str_each[i]);
		i++;
		// getch();
	}
	return str_each;
}

/* 从s中提取下标为n1~n2的字符组成一个新字符串，
   然后返回这个新串的首地址 */
char *substr(char *s, int n1, int n2)
{
	char *sp = (char *)calloc((n2 - n1 + 2), sizeof(char));
	int i, j = 0;
	for (i = n1; i < n2; i++)
	{
		sp[j++] = s[i];
	}
	sp[j] = ' ';
	return sp;
	free(sp);
}