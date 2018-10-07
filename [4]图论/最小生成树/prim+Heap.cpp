#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[400010];

int N, M, ans;
bool v[5010];
int d[5010];
int h[5010];

void add(int x, int y, int z)
{
	static int fuck = 0;
	a[++fuck] = (edge){y, z, h[x]};
	h[x] = fuck;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int x, y, z, i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, 1));
	memset(d, 0x3f, sizeof(d));
	d[1] = 0;
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (v[x] == true)
			continue;
		v[x] = true;
		ans += d[x];
		for (int i = h[x]; i != 0; i = a[i].ne)
		{
			if (v[a[i].v] == false && a[i].w < d[a[i].v])
			{
				d[a[i].v] = a[i].w;
				q.push(make_pair(d[a[i].v], a[i].v));
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (d[i] >= 0x3f3f3f3f)
		{
			printf("orz\n");
			return 0;
		}
	printf("%d\n", ans);
	return 0;
}
