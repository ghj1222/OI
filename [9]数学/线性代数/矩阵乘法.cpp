#include <cstring>
#include <cstdio>
const int p = 10007;

struct matrix
{
	int n, m;
	int a[233][233];
	matrix()
	{
		memset(this, 0, sizeof(matrix));
	}
};

matrix operator*(const matrix &a, const matrix &b)
{
	matrix ans;
	if (a.m != b.n) printf("fuck");
	for (int k = 1; k <= a.m; k++)
		for (int i = 1; i <= a.n; i++)
			for (int j = 1; j <= b.m; j++)
				(ans.a[i][j] += a.a[i][k] * b.a[k][j] % p) %= p;
	ans.n = a.n, ans.m = b.m;
	return ans;
}

matrix qpow(matrix a, int b)
{
	if (a.n != a.m)
		printf("fuck");
	matrix res;
	res.n = res.m = a.n;
	for (int i = 1; i <= res.n; i++) res.a[i][i] = 1;
	while (b > 0)
	{
		if (b & 1) res = res * a;
		a = a * a; b >>= 1;
	}
	return res;
}