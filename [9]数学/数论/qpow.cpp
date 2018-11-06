#include <bits/stdc++.h>
using namespace std;

int qpow(int a, int b, int c)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res;
}
//洛谷毒瘤
int main()
{
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	printf("%d^%d mod %d=%d\n", a, b, c, qpow(a % c, b, c) % c);
	return 0;
}
