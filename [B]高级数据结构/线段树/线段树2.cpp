#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
long long tree[maxn], lazy1[maxn], lazy2[maxn], T;
int l[maxn], mid[maxn], r[maxn], a[100010], n, m, p, L, R;
void pushdown(int x)
{
	(tree[x*2] *= lazy1[x]) %= p;
	(tree[x*2] += lazy2[x] * (r[x*2]-l[x*2]+1)) %= p;
	(lazy1[x*2] *= lazy1[x]) %= p;
	(lazy2[x*2] *= lazy1[x]) %= p;
	(lazy2[x*2] += lazy2[x]) %= p;
	(tree[x*2+1] *= lazy1[x]) %= p;
	(tree[x*2+1] += lazy2[x] * (r[x*2+1]-l[x*2+1]+1)) %= p;
	(lazy1[x*2+1] *= lazy1[x]) %= p;
	(lazy2[x*2+1] *= lazy1[x]) %= p;
	(lazy2[x*2+1] += lazy2[x]) %= p;
	lazy1[x] = 1, lazy2[x] = 0;
}
void pushup(int x)
{
	tree[x] = (tree[x * 2] + tree[x * 2 + 1]) % p;
}
void build(int x, int cl, int cr)
{
	l[x] = cl, r[x] = cr, lazy1[x] = 1;
	if (cl == cr) {tree[x] = a[cl]; return;}
	mid[x] = (cl + cr) / 2;
	build(x * 2, cl, mid[x]), build(x * 2 + 1, mid[x] + 1, cr);
	pushup(x);
}
void add(int x)
{
	if (l[x] > R || r[x] < L) return;
	if (l[x] >= L && r[x] <= R)
	{
		(tree[x] += (r[x] - l[x] + 1) * T % p) %= p;
		(lazy2[x] += T) %= p;
		return;
	}
	pushdown(x), add(x * 2), add(x * 2 + 1), pushup(x);
}
void mul(int x)
{
	if (l[x] > R || r[x] < L) return;
	if (l[x] >= L && r[x] <= R)
	{
		(tree[x] *= T) %= p;
		(lazy1[x] *= T) %= p;
		(lazy2[x] *= T) %= p;
		return;
	}
	pushdown(x), mul(x * 2), mul(x * 2 + 1), pushup(x);
}
long long query(int x)
{
	if (l[x] > R || r[x] < L) return 0;
	if (l[x] >= L && r[x] <= R) return tree[x];
	pushdown(x);
	return (query(x * 2) + query(x * 2 + 1)) % p;
}
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	for (int opd, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &opd, &L, &R);
		if (opd == 3) printf("%lld\n", query(1));
		else
		{
			scanf("%lld", &T);
			if (opd == 2) add(1);
			else mul(1);
		}
	}
	return 0;
}
