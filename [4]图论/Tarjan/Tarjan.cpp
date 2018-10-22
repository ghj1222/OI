#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w, ne;
} a[100010];

int dfn[10010], low[10010], s[10010], h[10010], f[10010];
int tot, top, cnt;
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
		cnt++;
		s[top + 1] = 0;//注意这句话一定要加，否则可能会出问题
		while (s[top + 1] != x)
		{
			f[s[top]] = cnt;
			v[s[top]] = false;
			top--;
		}
	}
	
}

int main()
{
	
	return 0;
}
