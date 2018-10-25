#include <bits/stdc++.h>
using namespace std;

namespace graph1
{
	struct edge
	{
		int v, ne;
	} a[100010];
	
	int h[10010], n, m;
	int val[10010], col[10010];
	int dfn[10010], low[10010];
	int s[10010], top, tot, cnt;
	bool v[10010];
	
	void search(int x)
	{
		dfn[x] = low[x] = ++tot;
		s[++top] = x;
		v[x] = true;
		for (int i = h[x]; i != 0; i = a[i].ne)
		{
			if (dfn[a[i].v] == 0)
			{
				search(a[i].v);
				low[x] = min(low[x], low[a[i].v]);
			}
			else if (v[a[i].v] == true)
			{
				low[x] = min(low[x], dfn[a[i].v]);
			}
		}
		if (dfn[x] == low[x])
		{
			s[top + 1] = 0;
			cnt++;
			while (s[top + 1] != x)
			{
				col[s[top]] = cnt;
				v[s[top]] = false;
				top--;
			}
		}
	}
	void work()
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &val[i]);
		}
		for (int x, i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &a[i].v);
			a[i].ne = h[x];
			h[x] = i;
		}
		for (int i = 1; i <= n; i++)
			if (dfn[i] == 0)
			{
				search(i);
			}
	}
};

namespace graph2
{
	struct edge
	{
		int v, ne;
	} a[100010];
	int h[10010], val[10010], n, tmp;
	int in[10010], s[10010], f[10010], top, ans;
	void add(int x, int y)
	{
		a[++tmp] = (edge){y, h[x]};
		h[x] = tmp;
		in[y]++;
	}
	
	void rebuild()
	{
		n = graph1::cnt;
		for (int i = 1; i <= graph1::n; i++)
		{
			val[graph1::col[i]] += graph1::val[i];
			for (int j = graph1::h[i]; j != 0; j = graph1::a[j].ne)
			{
				if (graph1::col[i] != graph1::col[graph1::a[j].v])
					add(graph1::col[i], graph1::col[graph1::a[j].v]);
			}
		}
		for (int i = 1; i <= n; i++)
			if (in[i] == 0)
				s[++top] = i;
		while (top > 0)
		{
			int x = s[top--];
			f[x] += val[x];
			ans = max(ans, f[x]);
			for (int i = h[x]; i != 0; i = a[i].ne)
			{
				in[a[i].v]--;
				f[a[i].v] = max(f[a[i].v], f[x]);
				if (in[a[i].v] == 0)
					s[++top] = a[i].v;
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
	graph1::work();
	graph2::rebuild();
	return 0;
}
