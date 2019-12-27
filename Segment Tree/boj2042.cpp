#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Update(vector<long long>& tree, int node, int s, int e, int idx, long long diff)
{
	// [s, e]에 idx가 포함되지 않는 경우 -> 탐색 중단
	if (idx < s || idx > e) return;

	// 그게 아니라면 diff만큼 증가시켜 합을 변경해줌
	tree[node] = tree[node] + diff;
	// leaf node인지 검사
	if (s != e)
	{
		Update(tree, node * 2, s, (s + e) / 2, idx, diff);
		Update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
	}
}

long long Sum(vector<long long>& tree, int node, int s, int e, int left, int right)
{
	// [left, right]와 [s, e]가 겹치지 않는 경우 -> 탐색 종료
	if (left > e || right < s) return 0;
	// [left, right]가 [s, e]를 완전히 포함하는 경우 -> 탐색 종료
	if (left <= s && e <= right) return tree[node];

	return Sum(tree, node * 2, s, (s + e) / 2, left, right) + Sum(tree, node * 2 + 1, (s + e) / 2 + 1, e, left, right);
}

// a : 배열 a, tree : segment tree, node : segment tree node number, node가 담당하는 합의 범위가 s~e
long long Init(vector<long long>& a, vector<long long>& tree, int node, int s, int e)
{
	// leaf node
	if (s == e) return tree[node] = a[s];
	// node의 왼쪽 자식은 node * 2, 오른쪽 자식은 node * 2 + 1
	// node가 담당하는 구간이 [s, e]라면 왼쪽 자식은 [s, (s+e)/2], 오른쪽 자식은 [(s+e)/2+1, e]를 담당
	// 재귀로 왼쪽 자식과 오른쪽 자식 트리를 만들고 그 합을 저장
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