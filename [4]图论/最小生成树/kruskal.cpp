#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u, v, w;
} a[200010];

int f[5010], n, m, ans;

bool fucked(const edge &a, const edge &b)
{
	return a.w < b.w;
}

int getf(int x)
{
	return f[x] == x ? x : f[x] = getf(f[x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	sort(a + 1, a + 1 + m, fucked);
	for (int i = 1; i <= n; i++) f[i] = i;
	int connected = n;
	for (int i = 1; i <= m; i++)
	{
		int x = getf(a[i].u), y = getf(a[i].v);
		if (x != y)
			f[x] = y, ans += a[i].w, connected--;
		if (connected == 1) break;
	}
	if (connected != 1) printf("orz\n");
	else printf("%d\n", ans);
	return 0;
}
