#include"../include/fmt_c_code.h"
#include"deal_with_file.c"
#include"kmpmatch.c"
#include"kmp.c"
#include"fmt_file.c"
#include"del_blank_line.c"
#include"cutstr.c"
#include"getname.c"
int main(int argc, char **argv)
{
	char *no_bl_filename = NULL;
	// 接受去掉换行符的源码的文件名
	char full_filename[FULL_FILENAME_LONG];
	// 接受待处理的源码完整文件名
	if (!argv[1])
	{
		printf("请选择源码(path+name)：");
		scanf("%s", full_filename);
		argv[1] = full_filename;
	}
	no_bl_filename = deal_with_file(argv[1]);
	printf("\n%s\n", no_bl_filename);
	fmt_file(no_bl_filename);
	// system("rm no_bl_*");
	free(no_bl_filename);
	return 0;
}