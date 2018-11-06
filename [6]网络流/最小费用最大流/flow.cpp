#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, ne, flow, cost;
}a[100010];

int h[5010], d[5010], v[5010], flow[5010], pe[5010], pv[5010];
int n, m, s, t, tmp = 1, maxflow, mincost;

void add(int u, int v, int flow, int cost)
{
	a[++tmp] = (edge){v, h[u], flow, cost};
	h[u] = tmp;
}

bool SPFA()
{
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(s);
	v[s] = true;
	d[s] = 0;
	flow[s] = 0x3f3f3f3f;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		v[x] = 0;
		for (int i = h[x]; i != 0; i = a[i].ne)
		{
			if (a[i].flow > 0 && d[x] + a[i].cost < d[a[i].v])
			{
				d[a[i].v] = d[x] + a[i].cost;
				pv[a[i].v] = x;
				pe[a[i].v] = i;
				flow[a[i].v] = min(flow[x], a[i].flow);
				if (v[a[i].v] == false)
				{
					v[a[i].v] = true;
					q.push(a[i].v);
				}
			}
		}
	}
	return d[t] < 0x3f3f3f3f;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int u, v, w, f, i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &u, &v, &w, &f);
		add(u, v, w, f);
		add(v, u, 0, -f);
	}
	while (SPFA())
	{
		int x = t;
		maxflow += flow[t];
		mincost += d[t] * flow[t];
		while (x != s)
		{
			a[pe[x]].flow -= flow[t];
			a[pe[x] ^ 1].flow += flow[t];
			x = pv[x];
		}
	}
	printf("%d %d\n", maxflow, mincost);
	return 0;
}
