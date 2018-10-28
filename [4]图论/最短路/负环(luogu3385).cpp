// 拨弄着　旧吉他　哼着四拍子的歌
// 回音中　一个人　仿佛颇悠然自得
// 等凉雨　的温度　将不安燥热中和
// 寻觅着　风的波折
#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[6010];

int h[2010], cnt[2010], d[2010];
bool v[2010];
int n, m, tmp;

void add(int x, int y, int z)
{
	a[++tmp] = (edge){y, z, h[x]};
	h[x] = tmp;
}

bool work()
{
	scanf("%d%d", &n, &m);tmp = 0; memset(h, 0, sizeof(h)); memset(cnt, 0, sizeof(cnt));
	memset(v, 0, sizeof(v));
	for (int x, y, z, i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z); if (z >= 0) add(y, x, z);
	}
	queue<int> q;
	q.push(1), v[1] = true;
	memset(d, 0x3f, sizeof(d)), d[1] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop(), v[x] = false, cnt[x]++;
		if (cnt[x] >= n) return true;
		for (int i = h[x]; i != 0; i = a[i].ne)
			if (d[x] + a[i].w < d[a[i].v])
			{
				d[a[i].v] = d[x] + a[i].w;
				if (v[a[i].v] == false)
					v[a[i].v] = true, q.push(a[i].v);
			}
	}
	return false;
}

int main()
{
	int t; scanf("%d", &t);
	while (t --> 0) puts(work() ? "YE5" : "N0");
	return 0;
}
