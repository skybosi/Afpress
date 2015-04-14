#ifndef _FMT_C_CODE_H_
#define _FMT_C_CODE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define STRS 23
#define FMT_STR_COUNT 13
	// 用于存放字符串匹配的位置坐标的个数
#define FMT_PATTENS_LONG 7
	// 包含了路径的文件名的长度，用于精确的选择待处理的源码文件
#define FULL_FILENAME_LONG 255
	// 格式化后的源码文件名(包含路径)长度，用于确定格式化后放置的源码文件
#define FMT_FILENAME_LONG 255
	// 第一步处理了后获得的无换行符的文件名长度
#define NO_BLANK_LINE_FILENAME_LONG 255
char *fmt_pattens[] = { "\t}", ";\t", "){", "\t{", ">\t", "\"\t", "*/" };

// 获取路径中的文件名
extern char *get_name(char *full_filename);
// 获取去掉换行符的源码文件函数
extern char *deal_with_file(char *filename);
// 获取格式化的源码文件函数
extern void fmt_file(char *full_filename);
// 获取格式化的源码文件的测试函数
extern void fmt_file_test(char *no_bl_filename);
// 获取一个字符串中的右起n个字符
extern char *right_n_str(char *dst, char *src, int n);
// 获取一个字符串中的左起n个字符
extern char *left_n_str(char *dst, char *src, int n);
// 删除一个字符串的前驱空格或tab
extern void del_blank_line(char *str);
// 模式匹配的三个函数
extern void getnext(char *t, int *next);
extern int kmp(char *s, char *t);
extern int *kmpmatch(char *buf, char **match, int match_count);
extern int cmpup(const void *a, const void *b);
// 字符串区间分段存储
extern char **cutstr(char *str, int *pos);
extern char *substr(char *s, int n1, int n2);
// 获取绝对路径中文件名函数
extern char *get_name(char *full_filename);
#endif
