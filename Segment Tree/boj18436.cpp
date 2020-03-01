#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Sum(vector<int>& t, int l, int r, int n, int s, int e)
{
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return t[n];

	int mid = (s + e) / 2;
	return Sum(t, l, r, n * 2, s, mid) + Sum(t, l, r, n * 2 + 1, mid + 1, e);
}

int Update(vector<int>& t, int n, int s, int e, int idx, int diff)
{
	if (idx < s || idx > e) return t[n];
	if (s == e) return t[n] = diff;

	int mid = (s + e) / 2;
	return t[n] = Update(t, n * 2, s, mid, idx, diff) + Update(t, n * 2 + 1, mid + 1, e, idx, diff);
}

int Init(vector<int>& v, vector<int>& t, int n, int s, int e)
{
	if (s == e)
		return t[n] = (v[s] & 1) == 1 ? 1 : 0;
	int mid = (s + e) / 2;
	return t[n] = Init(v, t, 2 * n, s, mid) + Init(v, t, 2 * n + 1, mid + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n;

	vector<int> vec(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	for (int i = 0; i < n; ++i) cin >> vec[i];

	Init(vec, tree, 1, 0, n - 1);

	cin >> m;

	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			if ((vec[b - 1] & 1) == 1 && (c & 1) == 0)
				Update(tree, 1, 0, n - 1, b - 1, 0);
			else if ((vec[b - 1] & 1) == 0 && (c & 1) == 1)
				Update(tree, 1, 0, n - 1, b - 1, 1);
			vec[b - 1] = c;
		}
		else if (a == 2)
			cout << c - b + 1 - Sum(tree, b - 1, c - 1, 1, 0, n - 1) << "\n";
		else if (a == 3)
			cout << Sum(tree, b - 1, c - 1, 1, 0, n - 1) << "\n";
	}
}