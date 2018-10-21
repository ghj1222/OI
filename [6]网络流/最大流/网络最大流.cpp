#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[200010];

int h[10010], d[10010];
int n, m, s, t, tmp = 1;

void add(int x, int y, int z)
{
	a[++tmp] = (edge){y, z, h[x]};
	h[x] = tmp;
}

bool bfs()
{
	memset(d, 0xff, sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = h[x]; i != 0; i = a[i].ne)
		{
			if (a[i].w > 0 && d[a[i].v] == -1)
			{
				d[a[i].v] = d[x] + 1;
				q.push(a[i].v);
			}
		}
	}
	return d[t] > 0;
}

int dfs(int x, int want)
{
	if (x == t)
		return want;
	int get = 0;
	for (int i = h[x]; i != 0; i = a[i].ne)
	{
		if (d[a[i].v] == d[x] + 1 && a[i].w > 0)
		{
			int f = dfs(a[i].v, min(want, a[i].w));
			a[i].w -= f;
			a[i ^ 1].w += f;
			want -= f;
			get += f;
		}
	}
	return get;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int x, y, z, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, 0);
	}
	int ans = 0;
	while (bfs())
		ans += dfs(s, 0x3f3f3f3f);
	printf("%d\n", ans);
	return 0;
}
