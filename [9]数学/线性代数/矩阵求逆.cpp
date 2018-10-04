#include <bits/stdc++.h>
using namespace std;

const int p = 1000000007;

int n;

struct matrix
{
	int a[400][400];
	
	void change1(int x, int y)
	{
		int t;
		for (int i = 0; i < n; i++)
			t = a[x][i], a[x][i] = a[y][i], a[y][i] = t;
	}
	
	void change2(int x, int k)
	{
		for (int i = 0; i < n; i++)
			a[x][i] = ((1LL * a[x][i] * k) % p + p) % p;
	}
	
	void change3(int x, int y, int k)
	{
		for (int i = 0; i < n; i++)
			a[x][i] = ((a[x][i] + 1LL * a[y][i] * k % p) % p + p) % p;
	}
	
}a, b;

int qpow(int x, int y)
{
	int res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = 1LL * res * x % p;
		x = 1LL * x * x % p;
		y >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a.a[i][j]);
	for (int i = 0; i < n; i++)
		b.a[i][i] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (a.a[i][j] != 0)
			{
				b.change1(i, j);
				a.change1(i, j);
				break;
			}
		if (a.a[i][i] == 0)
		{
			puts("No Solution");
			return 0;
		}
		int fuck = qpow(a.a[i][i], p - 2);
		b.change2(i, fuck);
		a.change2(i, fuck);
		for (int j = i + 1; j < n; j++)
		{
			b.change3(j, i, -a.a[j][i]);
			a.change3(j, i, -a.a[j][i]);
		}
	}
	for (int i = n - 2; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
		{
			b.change3(i, j, -a.a[i][j]);
			a.change3(i, j, -a.a[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", b.a[i][j], " \n"[j == n - 1]);
	return 0;
}
