#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int n;

int main()
{
	scanf("%d", &n);
	int f = 0;
	for (int x, i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		f = gcd(f, abs(x));
	}
	printf("%d\n", f);
	return 0;
}
/*
裴蜀定理

ax+by=c成立的充要条件为gcd(a, b) | c

*/