#include <bits/stdc++.h>
using namespace std;

int n, m, e, ans = 0;
bool g[1010][1010], vis[1010];
int linkx[1010], linky[1010];

bool search(int x)
{
	for (int y = 1; y <= m; y++)
	{
		if (g[x][y] && vis[y] == false)
		{
			vis[y] = true;
			if (linky[y] == -1 || search(linky[y]))
			{
				linkx[x] = y;
				linky[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d%d", &n, &m, &e);
	for (int x, y, i = 1; i <= e; i++)
	{
		scanf("%d%d", &x, &y);
		if (y <= m)
			g[x][y] = true;
	}
	memset(linkx, -1, sizeof(linkx));
	memset(linky, -1, sizeof(linky));
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		ans += search(i);
	}
	printf("%d\n", ans);
	return 0;
}
