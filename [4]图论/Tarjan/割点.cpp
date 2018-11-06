#include <bits/stdc++.h>
using namespace std;

struct edge{int v, ne;} a[200010];
int n, m, tmp, tot, ans;
int h[100010], dfn[100010], low[100010];
bool cut[100010];
void add(int x, int y) {a[++tmp] = (edge){y, h[x]}; h[x] = tmp;}
void search(int x, int fa)
{
	dfn[x] = low[x] = ++tot; int ch = 0;
	for (int i = h[x]; i != 0; i = a[i].ne)
	{
		if (dfn[a[i].v] == 0)
		{
			search(a[i].v, x), low[x] = min(low[x], low[a[i].v]);
			if (low[a[i].v] >= dfn[x] && x != fa)
				cut[x] = true;
			if (x == fa) ch++;
		}
		low[x] = min(low[x], dfn[a[i].v]);
	}
	if (x == fa && ch >= 2) cut[x] = true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int x, y, i = 1; i <= m; i++)
		scanf("%d%d", &x, &y), add(x, y), add(y, x);
	for (int i = 1; i <= n; i++) if (dfn[i] == 0) search(i, i);
	for (int i = 1; i <= n; i++) ans += cut[i];
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) if (cut[i]) printf("%d ", i);
	return 0;
}
