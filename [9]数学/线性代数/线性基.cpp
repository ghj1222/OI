#include <bits/stdc++.h>
using namespace std;

//loj 114 k ´óÒì»òºÍ

long long b[70], dou;
int n, q, top;
bool have0;

bool insert(long long x)
{
	for (int i = 55; i >= 0; i--)
	{
		if (x & (1LL << i))
		{
			if (b[i] == 0)
			{
				b[i] = x;
				return true;
			}
			x ^= b[i];
		}
	}
	return false;
}

void maintain()
{
	for (int i = 55; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if ((b[i] & (1LL << j)) && b[j])
				b[i] ^= b[j];
}

long long query(long long k)
{
	long long res = 0;
	if (k >= (1LL << top))
		return -1;
	for (int i = 0; i <= top; i++)
		if (k & (1LL << i))
			res ^= b[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &dou);
		if (insert(dou) == false)
			have0 = true;
	}
	maintain();
	for (int i = 0; i <= 55; i++)
		if (b[i] != 0)
			b[top++] = b[i];
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%lld", &dou);
		if (have0 == true)
			dou--;
		printf("%lld\n", query(dou));
	}
	return 0;
}
