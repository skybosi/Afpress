#include"../include/fmt_c_code.h"
// #include"kmpmatch.c"
void fmt_file(char *no_bl_filename)
{
	// fpi 已经去掉换行符的源码 fpo 生产的格式化的源码
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen(no_bl_filename, "r");
	// printf("%s\n", no_bl_filename);
	int *pos;
	char **str_each = NULL;
	char fmt_filename[FMT_FILENAME_LONG];
	char *filename;
	filename = get_name(no_bl_filename);
	sprintf(fmt_filename, "%s%s", "../test/fmt", filename);
	fpo = fopen(fmt_filename, "w");
	char buf[STRS] = { '\0' };
	while ((fgets(buf, STRS + 1, fpi)) != NULL)
	{
		// printf("buf=%s\n", buf);
		pos = kmpmatch(buf, fmt_pattens, FMT_PATTENS_LONG);
		str_each = cutstr(buf, pos);
		printf("分%d段\n", pos[0]);
		for (int i = 0; i < pos[0]; i++)
		{
			del_blank_line(str_each[i]);
			// printf("\033[1m\033[35mpos[%d]：%s\n\033[0m", i, str_each[i]);
			if (i != pos[0] - 1)
			{
				printf("前：\033[1m\033[35mpos[%d]%s\n\033[0m", i,
					   str_each[i]);
				fputs(str_each[i], fpo);
				fputc('\n', fpo);
			}
			else
			{
				printf("后：%s\n", str_each[i]);
				fputs(str_each[i], fpo);
			}
			free(str_each[i]);
		}
		free(str_each);
		// getch();
	}
	fclose(fpi);
	fclose(fpo);
	fpi = fpo = NULL;
}