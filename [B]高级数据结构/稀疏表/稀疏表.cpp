#include <bits/stdc++.h>
using namespace std;

int N, M, tat[100010], f[100010][18];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &f[i][0]);
	for (int i = 3; i <= N; i++)
		tat[i] = tat[(i + 1) / 2] + 1;
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i + (1 << j) - 1 <= N; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	for (int x, y, i = 1; i <= M; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", max(f[x][tat[y - x + 1]], f[y - (1 << tat[y - x + 1]) + 1][tat[y - x + 1]]));
	}
	return 0;
}
