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
������

ax+by=c�����ĳ�Ҫ����Ϊgcd(a, b) | c

*/