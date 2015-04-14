void getnext(char *t, int *next)
{
	int i = 0, j = -1, l = strlen(t);
	next[0] = -1;
	while (i < l)
		if (j == -1 || t[i] == t[j])
		{
			i++, j++;
			if (t[i] != t[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
}


// KMP 绠楁硶娉曪紝s鏂囨湰涓诧紝t 妯″紡涓?
int kmp(char *s, char *t)
{
	int ls = strlen(s), lt = strlen(t);
	int next[50];
	if (ls < lt)
		return -1;
	getnext(t, next);			// 璁＄畻next鏁扮粍 
	int i = 0, j = 0;
	while (i < ls && j < lt)
		if (j == -1 || s[i] == t[j])
			i++, j++;
		else
			j = next[j];
	if (j >= lt)
		return (i - lt + 1 );
	return -1;
}