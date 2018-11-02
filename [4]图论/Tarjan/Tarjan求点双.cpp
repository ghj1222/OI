#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, ne;
} a[200010];

int h[10010], n, m, tmp, cnt;
int dfn[10010], low[10010], tot;
int color[10010], s[10010], top;
bool v[10010];

void add(int x, int y)
{
	a[++tmp] = (edge){y, h[x]};
	h[x] = tmp;
}

void search(int x, int fa)
{
	dfn[x] = low[x] = ++tot;
	s[++top] = x, v[x] = true;
	for (int i = h[x]; i != 0; i = a[i].ne)
	{
		if (a[i].v != fa)
		{
			if (dfn[a[i].v] == 0)
			{
				search(a[i].v, x);
				low[x] = min(low[x], low[a[i].v]);
			}
			else if (v[a[i].v] == true)
				low[x] = min(low[x], dfn[a[i].v]);
		}
	}
	if (dfn[x] == low[x])
	{
		s[top + 1] = 0;
		cnt++;
		while (s[top + 1] != x)
		{
			color[s[top]] = cnt;
			v[s[top]] = false, top--;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int x, y, i = 1; i <= m; i++)
		scanf("%d%d", &x, &y), add(x, y), add(y, x);
	for (int i = 1; i <= n; i++)
		if (dfn[i] == 0) search(i, 0);
	return 0;
}
