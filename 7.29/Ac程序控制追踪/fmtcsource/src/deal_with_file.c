#include"../include/fmt_c_code.h"
//#include"kmpmatch.c"
char *deal_with_file(char *full_filename)
{
	// printf("%s\n", full_filename);
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen(full_filename, "r");
	if (!fpi)
	{
		printf("ERROR");
		exit(0);
	}
	char *no_bl_filename = NULL;
	no_bl_filename = (char *)calloc(NO_BLANK_LINE_FILENAME_LONG, sizeof(char));
	char *filename;
	filename = get_name(full_filename);
	sprintf(no_bl_filename, "%s%s", "../test/-", filename);
	fpo = fopen(no_bl_filename, "w");
	char buf[STRS] = { '\0' };
	int flag = 0;				// flag为真表示处于注释范围内
	int pos = -1;
	while ((fgets(buf, STRS + 1, fpi)) != NULL)
	{
		printf("%s\n", buf);
		del_blank_line(buf);
		pos = kmp(buf, "\n");
		if (kmp(buf, "//") >= 0)
			flag = 1;
		if (!flag && pos >= 0)
		{
			printf("[%d]", pos);
			if (buf[pos - 2] == ')')
				buf[pos - 1] = '\0';
			else
				buf[pos - 1] = '\t';
			printf("1:%s\n", buf);
		}
		else
		{
			if (pos >= 0)
				flag = 0;
			printf("2:%s\n", buf);
		}
		fputs(buf, fpo);
		//getch();
	}
	printf("ok");
	fclose(fpi);
	fclose(fpo);
	fpi = fpo = NULL;
	return no_bl_filename;
}