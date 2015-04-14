#include"../include/fmt_c_code.h"
//获取完全路径中的文件名
char *get_name(char *file)
{
#ifdef __linux
	char delims[] = "/";		// 分割符
#endif
#ifdef _WIN32
	char delims[] = "\\";		// 分割符
#endif
	char *token = NULL, *p[FULL_FILENAME_LONG];
	// p[WJmax] = calloc(Mmax, sizeof(char));
	int i = 0;
	p[i] = strtok(file, delims);
	while ((token = strtok(NULL, delims)) != NULL)
		p[++i] = token;
	// printf("最后一个字符串:%s\n", p[i]);
	return p[i];				// 返回真正的文件名
}