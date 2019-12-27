#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 987698769876;

long long getMin(vector<long long>& tree, int node, int s, int e, int left, int right)
{
	if (left > e || right < s) return INF;
	if (left <= s && e <= right) return tree[node];

	return min(getMin(tree, node * 2, s, (s + e) / 2, left, right), getMin(tree, node * 2 + 1, (s + e) / 2 + 1, e, left, right));
}

long long Init(vector<long long>& a, vector<long long>& tree, int node, int s, int e)
{
	if (s == e) return tree[node] = a[s];
	else return tree[node] = min(Init(a, tree, node * 2, s, (s + e) / 2), Init(a, tree, node * 2 + 1, (s + e) / 2 + 1, e));
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<long long> arr(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (int i = 0; i < N; ++i) cin >> arr[i];

	Init(arr, tree, 1, 0, N - 1);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << getMin(tree, 1, 0, N - 1, a - 1, b - 1) << "\n";
	}
}