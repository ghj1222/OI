#include <bits/stdc++.h>
using namespace std;
struct node{node *l, *r; int sum; };
node *root[200010];
int n, m, a[200010], ls[200010], ma;
node *build_tree(int l, int r)
{
	node *root = new node; root->sum = 0;
	if (l < r)
		root->l = build_tree(l, (l + r) / 2),
		root->r = build_tree((l + r) / 2 + 1, r);
	return root;
}
node *new_tree(node *old_tree, int l, int r, int key)
{
	node *root = new node; root->sum = old_tree->sum + 1;
	root->l = old_tree->l, root->r = old_tree->r;
	if (l < r)
	{
		if (key <= (l + r) / 2) root->l = new_tree(old_tree->l, l, (l + r) / 2, key);
		else root->r = new_tree(old_tree->r, (l + r) / 2 + 1, r, key);
	}
	return root;
}
int query(node *tree1, node *tree2, int l, int r, int key)
{
	if (l >= r) return l;
	int sz = tree1->l->sum - tree2->l->sum;
	if (sz >= key) return query(tree1->l, tree2->l, l, (l + r) / 2, key);
	else return query(tree1->r, tree2->r, (l + r) / 2 + 1, r, key - sz);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ls[i] = a[i];
	sort(ls + 1, ls + 1 + n);
	ma = unique(ls + 1, ls + 1 + n) - ls - 1;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(ls + 1, ls + 1 + ma, a[i]) - ls;
	root[0] = build_tree(1, ma);
	for (int i = 1; i <= n; i++) root[i] = new_tree(root[i - 1], 1, ma, a[i]);
	for (int x, y, z, i = 1; i <= m; i++)
		scanf("%d%d%d", &x, &y, &z),
		printf("%d\n", ls[query(root[y], root[x - 1], 1, ma, z)]);
	return 0;
}
