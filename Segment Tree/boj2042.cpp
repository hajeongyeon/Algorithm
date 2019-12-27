#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Update(vector<long long>& tree, int node, int s, int e, int idx, long long diff)
{
	// [s, e]�� idx�� ���Ե��� �ʴ� ��� -> Ž�� �ߴ�
	if (idx < s || idx > e) return;

	// �װ� �ƴ϶�� diff��ŭ �������� ���� ��������
	tree[node] = tree[node] + diff;
	// leaf node���� �˻�
	if (s != e)
	{
		Update(tree, node * 2, s, (s + e) / 2, idx, diff);
		Update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
	}
}

long long Sum(vector<long long>& tree, int node, int s, int e, int left, int right)
{
	// [left, right]�� [s, e]�� ��ġ�� �ʴ� ��� -> Ž�� ����
	if (left > e || right < s) return 0;
	// [left, right]�� [s, e]�� ������ �����ϴ� ��� -> Ž�� ����
	if (left <= s && e <= right) return tree[node];

	return Sum(tree, node * 2, s, (s + e) / 2, left, right) + Sum(tree, node * 2 + 1, (s + e) / 2 + 1, e, left, right);
}

// a : �迭 a, tree : segment tree, node : segment tree node number, node�� ����ϴ� ���� ������ s~e
long long Init(vector<long long>& a, vector<long long>& tree, int node, int s, int e)
{
	// leaf node
	if (s == e) return tree[node] = a[s];
	// node�� ���� �ڽ��� node * 2, ������ �ڽ��� node * 2 + 1
	// node�� ����ϴ� ������ [s, e]��� ���� �ڽ��� [s, (s+e)/2], ������ �ڽ��� [(s+e)/2+1, e]�� ���
	// ��ͷ� ���� �ڽİ� ������ �ڽ� Ʈ���� ����� �� ���� ����
	else return tree[node] = Init(a, tree, node * 2, s, (s + e) / 2) + Init(a, tree, node * 2 + 1, (s + e) / 2 + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<long long> arr(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (int i = 0; i < N; ++i) cin >> arr[i];

	Init(arr, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; ++i)
	{
		int a; cin >> a;

		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;

			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			Update(tree, 1, 0, N - 1, b - 1, diff);
		}
		else
		{
			int b;
			long long c;
			cin >> b >> c;

			cout << Sum(tree, 1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
}