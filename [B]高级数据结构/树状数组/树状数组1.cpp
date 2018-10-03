#include <bits/stdc++.h>
using namespace std;

int N, M;

struct FenwickTree
{
	int a[500010];
	
	void modify(int x, int k)
	{
		for (int i = x; i <= N; i += i & -i)
			a[i] += k;
	}
	
	int query(int x)
	{
		int ans = 0;
		for (int i = x; i > 0; i -= i & -i)
			ans += a[i];
		return ans;
	}
}Tree;

int main()
{
	scanf("%d%d", &N, &M);
	for (int x, i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		Tree.modify(i, x);
	}
	for (int opd, x, y, i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &opd, &x, &y);
		if (opd == 1)
			Tree.modify(x, y);
		if (opd == 2)
			printf("%d\n", Tree.query(y) - Tree.query(x - 1));
	}
	return 0;
}
