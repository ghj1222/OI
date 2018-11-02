#include <bits/stdc++.h>
using namespace std;

int p1 = 19260817, p2 = 20020303, base = 233;

pair<int, int> gethash(char *s)
{
	long long res1 = 0, res2 = 0;
	for (char *i = s; (*i) != 0; i++)
	{
		res1 = (res1 * base + (*i)) % p1;
		res2 = (res2 * base + (*i)) % p2;
	}
	return make_pair((int)res1, (int)res2);
}

int n;
pair<int, int> sb[10010];
char tmp[10230];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", tmp);
		sb[i] = gethash(tmp);
	}
	sort(sb + 1, sb + 1 + n);
	printf("%lld\n", unique(sb + 1, sb + 1 + n) - sb - 1);
	return 0;
}
