#include <bits/stdc++.h>
#define int long long
using namespace std;
const long long inf = 998244353;
struct _TpEdge {int u, v, w; bool choose;} e[300010];
int n, m, mst, ans = inf;
struct _TpDs
{
	int f[100010];
	void init() {for (int i = 1; i <= n; i++)f[i] = i;}
	int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}
} ds;
struct _TpGraph
{
	struct _TpEdge {int v, w, ne;}a[200010];
	int tmp, h[100010], d[100010], fa[100010][18], m1[100010][18], m2[100010][18];
	void add(int x, int y, int z){a[++tmp] = (_TpEdge){y, z, h[x]}; h[x] = tmp;}
	void search(int x)
	{
		for (int i = h[x]; i != 0; i = a[i].ne)
			if (fa[x][0] != a[i].v)
			{
				fa[a[i].v][0] = x, d[a[i].v] = d[x] + 1;
				m1[a[i].v][0] = a[i].w, m2[a[i].v][0] = -inf;
				search(a[i].v);
			}
	}
	void dp()
	{
		int temp[4];
		for (int j = 1; j <= 17; j++)
			for (int i = 1; i <= n; i++)
			{
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
				temp[0] = m1[i][j - 1];
				temp[1] = m2[i][j - 1];
				temp[2] = m1[fa[i][j - 1]][j - 1];
				temp[3] = m2[fa[i][j - 1]][j - 1];
				sort(temp, temp + 4, greater<int>());
				unique(temp, temp + 4, greater<int>());
				m1[i][j] = temp[0];
				m2[i][j] = temp[1];
			}
	}
	pair<int, int> lca(int x, int y)
	{
		int temp[6];
		int max1 = -inf, max2 = -inf;
		if (d[x] < d[y]) swap(x, y);
		int dis = d[x] - d[y];
		for (int i = 17; i >= 0; i--)
			if (dis & (1 << i))
			{
				temp[0] = max1;
				temp[1] = max2;
				temp[2] = m1[x][i];
				temp[3] = m2[x][i];
				sort(temp, temp + 4, greater<int>());
				unique(temp, temp + 4, greater<int>());
				max1 = temp[0];
				max2 = temp[1];
				x = fa[x][i];
			}
		if (x == y)
			return make_pair(max1, max2);
		for (int i = 17; i >= 0; i--)
		{
			if (fa[x][i] != fa[y][i])
			{
				temp[0] = max1;
				temp[1] = max2;
				temp[2] = m1[x][i];
				temp[3] = m2[x][i];
				temp[4] = m1[y][i];
				temp[5] = m2[y][i];
				sort(temp, temp + 6, greater<int>());
				unique(temp, temp + 6, greater<int>());
				max1 = temp[0];
				max2 = temp[1];
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		temp[0] = max1;
		temp[1] = max2;
		temp[2] = m1[x][0];
		temp[3] = m2[x][0];
		temp[4] = m1[y][0];
		temp[5] = m2[y][0];
		sort(temp, temp + 6, greater<int>());
		unique(temp, temp + 6, greater<int>());
		return make_pair(temp[0], temp[1]);
	}
} graph;
bool operator<(const _TpEdge &a, const _TpEdge &b) {return a.w < b.w;}
signed main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + 1 + m); ds.init();
	for (int i = 1; i <= m; i++)
		if (ds.getf(e[i].u) != ds.getf(e[i].v))
		{
			ds.f[ds.getf(e[i].u)] = ds.getf(e[i].v);
			e[i].choose = true;
			mst += e[i].w;
		}
	for (int i = 1; i <= m; i++)
		if (e[i].choose == true)
			graph.add(e[i].u, e[i].v, e[i].w), graph.add(e[i].v, e[i].u, e[i].w);
	graph.search(1); graph.dp();
	for (int i = 1; i <= m; i++)
		if (e[i].choose == false)
		{
			pair<int, int> fuck = graph.lca(e[i].u, e[i].v);
			if (e[i].w > fuck.first)
				ans = min(ans, e[i].w - fuck.first);
			if (e[i].w > fuck.second)
				ans = min(ans, e[i].w - fuck.second);
		}
	printf("%lld\n", mst + ans);
	return 0;
}
