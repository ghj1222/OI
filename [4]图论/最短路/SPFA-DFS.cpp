#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[500010];

int h[100010], d[100010], n, m, tmp;
bool v[100010];

void add(int x, int y, int z)
{
	a[++tmp] = (edge){y, z, h[x]};
	h[x] = tmp;
}

//洛谷板子题T得飞起
void spfa(int x)
{
	for (int i = h[x]; i != 0; i = a[i].ne)
	{
		if (d[x] + a[i].w < d[a[i].v])
		{
			d[a[i].v] = d[x] + a[i].w;
			v[a[i].v] = true;
			spfa(a[i].v);
			v[a[i].v] = false;
		}
	}
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
	spfa(src);
	for (int i = 1; i <= n; i++)
		printf("%d%c", d[i] == 0x3f3f3f3f ? 0x7fffffff : d[i], " \n"[i == n]);
	return 0;
}
