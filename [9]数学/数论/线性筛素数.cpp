#include <bits/stdc++.h>
using namespace std;

int prime[10000010], tot;
bool vis[10000010];

int main()
{
	vis[1] = 1;
	for (int i = 2; i <= 10000000; i++)
	{
		if (vis[i] == false) prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= 10000000; j++)
		{
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &n);
		printf("%s\n", vis[n] ? "No" : "Yes");
	}
	return 0;
}
