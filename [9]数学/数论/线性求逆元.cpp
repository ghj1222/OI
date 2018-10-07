#include <bits/stdc++.h>
using namespace std;

long long inv[3000010], n, p;

int main()
{
	cin >> n >> p;
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = (p - (p / i) * inv[p % i] % p) % p;
	for (int i = 1; i <= n; i++)
		cout << inv[i] << '\n';
	return 0;
}
/*
设 p = ki + r, r < i, 1 < i < p
则 ki + r \equiv 0 \pmod p
乘上i^{-1}和r^{-1}得到
kr^{-1} + i^{-1} \equiv 0 \pmod p
i^{-1} \equiv -kr^{-1} \pmod p
i^{-1} \equiv -\left\lfloor \frac p i \right\rfloor (p \ \mathrm{mod}\ i)^{-1}\pmod p
*/
