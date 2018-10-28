#include <bits/stdc++.h>
using namespace std;

char a[1000010], b[1000010];
int lrt[1000010], n, m;

int main()
{
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	int k = 0;
	for (int i = 2; i <= m; i++)
	{
		while (k != 0 && b[i] != b[k + 1])
			k = lrt[k];
		if (b[i] == b[k + 1])
			k++;
		lrt[i] = k;
	}
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (j > 0 && b[j + 1] != a[i])
			j = lrt[j];
		if (b[j + 1] == a[i])
			j++;
		if (j == m)
			printf("%d\n", i - j + 1), j = lrt[j];
	}
	for (int i = 1; i <= m; i++) printf("%d%c", lrt[i], i == m ? '\n' : ' ');
	return 0;
}
/*
KMP字符串匹配
通过本代码的思路可以xjb yy出ac自动机
*/