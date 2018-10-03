struct edge
{
	int v, w, ne;
} a[500010];

int h[100010], dis[100010], n, m, tmp;

void add(int x, int y, int z)
{
	a[++tmp] = (edge){y, z, h[x]};
	h[x] = tmp;
}

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(v, 0, sizeof(v));
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (v[x] == true)
			continue;
		v[x] = true;
		for (int i = h[x]; i != 0; i = a[i].ne)
		{
			if (v[a[i].v] == false && d[x] + a[i].w < d[a[i].v])
			{
				d[a[i].v] = d[x] + a[i].w;
				q.push(make_pair(d[a[i].v], a[i].v);
			}
		}
	}
}
