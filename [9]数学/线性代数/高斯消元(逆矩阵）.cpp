// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
int n;
struct matrix
{
	double a[100][110];
	void change1(int x, int y)
	{
		double t;
		for (int i = 0; i < n; i++)
			t = a[x][i], a[x][i] = a[y][i], a[y][i] = t;
	}
	void change2(int x, double k)
	{
		for (int i = 0; i < n; i++) a[x][i] *= k;
	}
	void change3(int x, int y, double k)
	{
		for (int i = 0; i < n; i++) a[x][i] += a[y][i] * k;
	}
}a, b;
double vec[110];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%lf", &a.a[i][j]);
		scanf("%lf", &vec[i]);
	}
	for (int i = 0; i < n; i++) b.a[i][i] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (a.a[i][j] != 0)
			{
				b.change1(i, j), a.change1(i, j);
				break;
			}
		if (a.a[i][i] == 0)
		{
			puts("No Solution");
			return 0;
		}
		double fuck = 1 / a.a[i][i];
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
	{
		double res = 0;
		for (int j = 0; j < n; j++)
			res += b.a[i][j] * vec[j];
		printf("%.2f\n", res);
	}
	return 0;
}
