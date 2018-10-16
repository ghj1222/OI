#include <bits/stdc++.h>
using namespace std;

struct segmenttree
{
	long long sum[300000], lazy[300000];
	
	void pushup(int x)
	{
		sum[x] = sum[x * 2] + sum[x * 2 + 1];
	}
	
	void pushdown(int x, int l, int mid, int r)
	{
		sum[x * 2] += (mid - l + 1) * lazy[x];
		sum[x * 2 + 1] += (r - mid) * lazy[x];
		lazy[x * 2] += lazy[x];
		lazy[x * 2 + 1] += lazy[x];
		lazy[x] = 0;
	}
	
	void build(int x, int l, int r, long long *a)
	{
		if (l == r)
		{
			sum[x] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(x * 2, l, mid, a);
		build(x * 2 + 1, mid + 1, r, a);
		pushup(x);
	}
	
	void modify(int x, int L, int R, int cl, int cr, int k)
	{
		if (R < cl || cr < L)
			return;
		if (L <= cl && cr <= R)
		{
			sum[x] += k * (cr - cl + 1);
			lazy[x] += k;
			return;
		}
		int mid = (cl + cr) / 2;
		pushdown(x, cl, mid, cr);
		modify(x * 2, L, R, cl, mid, k);
		modify(x * 2 + 1, L, R, mid + 1, cr, k);
		pushup(x);
	}
	
	long long query(int x, int L, int R, int cl, int cr)
	{
		if (R < cl || cr < L)
			return 0;
		if (L <= cl && cr <= R)
		{
			return sum[x];
		}
		int mid = (cl + cr) / 2;
		pushdown(x, cl, mid, cr);
		return query(x * 2, L, R, cl, mid) + query(x * 2 + 1, L, R, mid + 1, cr);
	}
} Tree;

int N, M;
long long a[100010];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	Tree.build(1, 1, N, a);
	int opd, x, y;
	long long k;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &opd, &x, &y);
		if (opd == 1)
		{
			scanf("%lld", &k);
			Tree.modify(1, x, y, 1, N, k);
		}
		if (opd == 2)
		{
			printf("%lld\n", Tree.query(1, x, y, 1, N));
		}
	}
	return 0;
}
