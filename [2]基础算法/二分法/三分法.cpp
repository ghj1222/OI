#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

int n;
double l, r, a[15];

double f(double x)
{
	double res = 0, tmp = 1;
	for (int i = 0; i <= n; i++)
	{
		res = res + tmp * a[i];
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
		double lmid = (2 * l + r) / 3;
		double rmid = (l + 2 * r) / 3;
		if (f(lmid) < f(rmid))
			l = lmid;
		else
			r = rmid;
	}
	printf("%.5f\n", l);
	return 0;
}
