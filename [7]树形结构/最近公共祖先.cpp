#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, ne;
} a[1000010];

int n, m, s, tmp;
int fa[500010][20], d[500010], h[500010];

void add(int x, int y)
{
	a[++tmp] = (edge){y, h[x]};
	h[x] = tmp;
}

void search(int x)
{
	for (int i = h[x]; i != 0; i = a[i].ne)
	{
		if (fa[x][0] != a[i].v)
		{
			fa[a[i].v][0] = x;
			d[a[i].v] = d[x] + 1;
			search(a[i].v);
		}
	}
}

int lca(int x, int y)
{
	if (d[x] < d[y])
		swap(x, y);
	int dis = d[x] - d[y];
	for (int i = 19; i >= 0; i--)
		if (dis & (1 << i))
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 19; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int x, y, i = 1; i < n; i++)
		scanf("%d%d", &x, &y), add(x, y), add(y, x);
	search(s);
	for (int j = 1; j <= 19; j++)
		for (int i = 1; i <= n; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for (int x, y, i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}
