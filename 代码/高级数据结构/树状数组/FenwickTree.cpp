int lowbit(int x)
{
	return x & -x;
}

const int MAXN = 100010;
int N = 100000;

struct FenwickTree
{
	int c[MAXN];
	
	FenwickTree()
	{
		memset(c, 0, sizeof(c));
	}
	
	void update(int x, int k)
	{
		for (int i = x; i <= N; i += lowbit(i))
			c[i] += k;
	}
	
	int query(int x)
	{
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += c[i];
		return res;
	}
};
