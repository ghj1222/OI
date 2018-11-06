#include <bits/stdc++.h>
using namespace std;
int n, m, f[10010], h[10010];
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]);}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int x, y, z, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) f[getf(y)] = getf(z);
		else printf("%s\n", getf(y) == getf(z) ? "Y" : "N");
	}
	return 0;
}
