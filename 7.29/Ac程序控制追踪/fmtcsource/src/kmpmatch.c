#include"../include/fmt_c_code.h"
int *kmpmatch(char *buf, char **match, int match_count)
{
	int count = 0, pos_each = -1, i = 2;
	int next[50];
	int *pos = NULL;
	pos = (int *)calloc(FMT_STR_COUNT, sizeof(int));
	while (count < match_count)
	{
		// printf("{%d} %s\n", count, match[count]);
		getnext(match[count], next);
		pos_each = kmp(buf, match[count]);
		if (pos_each > 0)
		{
			// printf("%d ", pos_each);
			pos[i++] = pos_each + 1;
			// printf("%d [%d]", pos[count],count);
			// printf("[%s]\n", match[count]);
			printf("\n%d：\033[1m\033[32m%s"
				   "\033[47;31m\thead breaking......\n\033[0m",count, match[count]);
		}
		count++;

	}
	qsort(pos, i, sizeof(int), cmpup);
	pos[0] = i - 1;
	pos[i] = strlen(buf);
	// count = 0;
	return pos;
	free(pos);
}

// 升序排列
int cmpup(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}