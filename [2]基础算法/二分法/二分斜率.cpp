#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

int n;
double l, r, a[15];

double f(double x)
{
	double res = 0, tmp = 1;
	for (int i = 1; i <= n; i++)
	{
		res = res + tmp * a[i] * i;
		tmp *= x;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	scanf("%lf%lf", &l, &r);
	for (int i = n; i >= 0; i--)
		scanf("%lf", &a[i]);
	while (r - l > eps)
	{
		double mid = (l + r) / 2;
		if (f(mid) < 0)
			r = mid;
		else
			l = mid;
	}
	printf("%.5f\n", l);
	return 0;
}
