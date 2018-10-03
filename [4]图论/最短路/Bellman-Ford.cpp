#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[500010];

int h[100010], d[100010], n, m, tmp;

void add(int x, int y, int z)
{
	a[++tmp] = (edge){y, z, h[x]};
	h[x] = tmp;
}

void update()
{
	for (int i = 1; i <= n; i++)
		for (int j = h[i]; j != 0; j = a[j].ne)
			d[a[j].v] = min(d[a[j].v], d[i] + a[j].w);
}

int main()
{
	int src;
	scanf("%d%d%d", &n, &m, &src);
	for (int x, y, z, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	memset(d, 0x3f, sizeof(d));
	d[src] = 0;
	for (int i = 1; i < n; i++)
		update();
	for (int i = 1; i <= n; i++)
		printf("%d%c", d[i] == 0x3f3f3f3f ? 0x7fffffff : d[i], " \n"[i == n]);
	return 0;
}
//T得飞起
