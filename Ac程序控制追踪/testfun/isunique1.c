bool isunique1(char *str)
{
	bool a[256] = { 0 };
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int v = (int)str[i];
		if (a[v])
			return false;
		a[v] = true;
	}
}