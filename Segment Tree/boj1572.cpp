#include <iostream>
#include <vector>
using namespace std;

#define MAX 65536

int n, k;
long long answer, tree[250001];

long long Update(int idx, int val, int node, int s, int e)
{
	if (idx < s || idx > e) return tree[node];
	if (s == e) return tree[node] += val;

	int mid = (s + e) / 2;
	return tree[node] = Update(idx, val, node * 2, s, mid) + Update(idx, val, node * 2 + 1, mid + 1, e);
}

long long Find(long long val, int node, int s, int e)
{
	if (s == e) return s;

	int mid = (s + e) / 2;

	if (tree[node * 2] >= val) return Find(val, node * 2, s, mid);
	return Find(val - tree[node * 2], node * 2 + 1, mid + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	vector<long long> temp(n);
	for (int i = 0; i < n; ++i) 
		cin >> temp[i];

	for (int i = 0; i < k - 1; ++i)
		Update(temp[i], 1, 1, 0, MAX - 1);

	for (int i = k - 1; i < n; ++i)
	{
		Update(temp[i], 1, 1, 0, MAX - 1);
		answer += Find((k + 1) / 2, 1, 0, MAX - 1);
		Update(temp[i - k + 1], -1, 1, 0, MAX - 1);
	}

	cout << answer;
}