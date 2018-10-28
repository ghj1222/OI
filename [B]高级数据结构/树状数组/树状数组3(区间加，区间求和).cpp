#include <bits/stdc++.h>
using namespace std;
//线段树1
int n, m;
long long z;

struct FenwickTree
{
	long long a[100010], c[100010];
	void modify(int x, long long k)
	{
		for (int i = x; i <= n; i += i & -i)
		{
			c[i] += x * k;
			a[i] += k;
		}
	}
	
	long long query(int x)
	{
		long long ans1 = 0, ans2 = 0;
		for (int i = x; i > 0; i -= i & -i)
		{
			ans1 += a[i];
			ans2 += c[i];
		}
		return ans1 * (x + 1) - ans2;
	}
	
	void add(int l, int r, long long k)
	{
		modify(l, k), modify(r + 1, -k);
	}
	
	long long query(int l, int r)
	{
		return query(r) - query(l - 1);
	}
} tree;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &z);
		tree.add(i, i, z);
	}
	for (int opd, x, y, i = 1; i <= m; i++)
	{
		scanf("%d", &opd);
		if (opd == 1)
		{
			scanf("%d%d%lld", &x, &y, &z);
			tree.add(x, y, z);
		}
		if (opd == 2)
		{
			scanf("%d%d", &x, &y);
			printf("%lld\n", tree.query(x, y));
		}
	}
	return 0;
}
