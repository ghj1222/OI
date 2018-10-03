int qpow(int x, int y, int p)
{
	int res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = res * x % p;
		x = x * x % p;
		y >>+ 1;
	}
	return res;
}
