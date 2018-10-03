#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *l, *r;
    int val;
};

node *root[1000010];

int n, m, a[1000010];

node *build_tree(int l, int r)
{
    if (l > r)
        return 0;
    node *x = new node;
    if (l == r)
    {
        x->val = a[l];
        return x;
    }
    int mid = (l + r) / 2;
    x->val = a[mid];
    x->l = build_tree(l, mid - 1);
    x->r = build_tree(mid + 1, r);
    return x;
}

node *modify(node *old_tree, int l, int r, int loc, int val)
{
    node *x = new node;
    if (l == r)
    {
        x->val = val;
        return x;
    }
    int mid = (l + r) / 2;
    if (mid == loc)
    {
        x->val = val;
        x->l = old_tree->l;
        x->r = old_tree->r;
        return x;
    }
    if (mid < loc)
    {
        x->val = old_tree->val;
        x->l = old_tree->l;
        x->r = modify(old_tree->r, mid + 1, r, loc, val);
    }
    if (mid > loc)
    {
        x->val = old_tree->val;
        x->l = modify(old_tree->l, l, mid - 1, loc, val);
        x->r = old_tree->r;
    }
    return x;
}

int query(node *x, int l, int r, int loc)
{
    int mid = (l + r) / 2;
    if (loc == mid)
        return x->val;
    if (loc < mid)
        return query(x->l, l, mid - 1, loc);
    if (loc > mid)
        return query(x->r, mid + 1, r, loc);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    root[0] = build_tree(1, n);
    for (int ver, opd, loc, val, i = 1; i <= m; i++)
    {
        scanf("%d%d", &ver, &opd);
        if (opd == 1)
        {
            scanf("%d%d", &loc, &val);
            root[i] = modify(root[ver], 1, n, loc, val);
        }
        if (opd == 2)
        {
            scanf("%d", &loc);
            printf("%d\n", query(root[ver], 1, n, loc));
            root[i] = root[ver];
        }
    }
    return 0;
}