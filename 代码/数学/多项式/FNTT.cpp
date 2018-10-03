#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define MAXN 4323432
int n, m;
int r[MAXN], a[MAXN], b[MAXN], ans[MAXN];

int qpow(int x, int y)
{
    int ans = 1;
    while (y > 0)
    {
        if (y & 1)
            ans = (1LL * ans * x) % p;
        x = (1LL * x * x) % p;
        y >>= 1;
    }
    return ans;
}

void FNTT(int *A, int len, int flag)
{
    int gn, g, t, *A0, *A1;
    for (int i = 0; i < len; i++)
        if (i < r[i])
            swap(A[i], A[r[i]]);
    for (int i = 1; i < len; i <<= 1)
    {
        gn = qpow(3, (p - 1) / (i * 2));
        for (int j = 0; j < len; j += (i << 1))
        {
            g = 1;
            A0 = A + j;
            A1 = A0 + i;
            for (int k = 0; k < i; k++, A0++, A1++, g = (1LL * g * gn) % p)
            {
                t = (1LL * (*A1) * g) % p;
                (*A1) = (((*A0) - t) % p + p) % p;
                (*A0) = ((*A0) + t) % p;
            }
        }
    }
    if (flag == -1)
    {
        reverse(A + 1, A + len);
        int inv = qpow(len, p - 2);
        for (int i = 0; i < len; i++)
            A[i] = (1LL * A[i] * inv) % p;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= m; i++)
        scanf("%d", &b[i]);
    int len = 1, bin = 0;
    for (; len <= n + m; len <<= 1, bin++);
    for (int i = 0; i < len; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (bin - 1));
    FNTT(a, len, 1);
    FNTT(b, len, 1);
    for (int i = 0; i < len; i++)
        ans[i] = (1LL * a[i] * b[i]) % p;
    FNTT(ans, len, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%d%c", ans[i], i == n + m ? '\n' : ' ');
    return 0;
}