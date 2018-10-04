#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[100010], r[100010], f[100010], val[100010], d[100010];

int getf(int x)
{
	while (f[x] != 0)
		x = f[x];
	return x;
}

int merge(int x, int y)
{
	if (x == 0 || y == 0)
		return x + y;
	if (val[x] > val[y] || (val[x] == val[y] && x > y))
		swap(x, y);
	r[x] = merge(r[x], y);
	f[r[x]] = x;
	if (d[l[x]] < d[r[x]])
		swap(l[x], r[x]);
	d[x] = d[r[x]] + 1;
	return x;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (int opd, x, y, i = 1; i <= m; i++)
	{
		scanf("%d", &opd);
		if (opd == 1)
		{
			scanf("%d%d", &x, &y);
			if (x == y || val[x] == -1 || val[y] == -1)
				continue;
			merge(getf(x), getf(y));
		}
		if (opd == 2)
		{
			scanf("%d", &x);
			if (val[x] == -1)
				puts("-1");
			else
			{
				x = getf(x);
				printf("%d\n", val[x]);
				val[x] = -1;
				f[l[x]] = f[r[x]] = 0;
				merge(l[x], r[x]);
			}
		}
	}
	return 0;
}
