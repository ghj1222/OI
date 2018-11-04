#include <bits/stdc++.h>
using namespace std;

const char sp = '$';
const int maxn = 20000010;

char aa[maxn], a[maxn];
int m[maxn], n, k;

int main()
{
	scanf("%s", aa + 1);
	k = strlen(aa + 1);
	for (int i = 1; i <= k; i++)
		a[i * 2 - 1] = aa[i], a[i * 2] = sp;
	a[0] = sp;
	n = 2 * k;
	int more = 0, pos = 0;
	for (int i = 1; i <= n; i++)
	{
		if (more > i)
			m[i] = min(m[2 * pos - i], more - i);
		else
			m[i] = 1;
		while (i + m[i] <= n && i - m[i] >= 0 && a[i + m[i]] == a[i - m[i]])
			m[i]++;
		if (i + m[i] - 1 > more) more = i + m[i] - 1, pos = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, m[i] - 1);
	printf("%d\n", ans);
	return 0;
}
