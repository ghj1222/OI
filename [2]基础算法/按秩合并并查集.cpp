#include <bits/stdc++.h>
using namespace std;
int n, m, f[10010], h[10010];
int getf(int x) { return f[x] == x ? x : getf(f[x]);}
void merge(int x, int y)
{
	if (h[x] < h[y]) swap(x, y);
	f[y] = x;
	if (h[y] + 1 > h[x]) h[x] = h[y] + 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int x, y, z, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) merge(getf(y), getf(z));
		else printf("%s\n", getf(y) == getf(z) ? "Y" : "N");
	}
	return 0;
}
