#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int candy[1000001];

class segmentTree {
public:
	int* segment;

	segmentTree(int* given, int n);
	int Init(int* given, int s, int e, int node);
	int Find(int s, int e, int node, int left, int right);
	int Update(int idx, int val, int node, int s, int e);
	int getIdx(int val, int node, int s, int e);
};

segmentTree::segmentTree(int* given, int n)
{
	int x = (int)ceil(log(n) / log(2));
	int size = (int)pow(2, x) * 2;
	segment = new int[size];
	Init(given, 0, n - 1, 1);
}

int segmentTree::Init(int* given, int s, int e, int node)
{
	if (s == e) return segment[node] = given[s];

	int mid = (s + e) / 2;
	return segment[node] = Init(given, s, mid, node * 2) + Init(given, mid + 1, e, node * 2 + 1);
}

int segmentTree::Find(int left, int right, int node, int s, int e)
{
	if (left > s || right < e) return 0;
	if (left <= s && right >= e) return segment[node];

	int mid = (s + e) / 2;
	return Find(left, right, node * 2, s, mid) + Find(left, right, node * 2 + 1, mid + 1, e);
}

int segmentTree::Update(int idx, int val, int node, int s, int e)
{
	if (idx < s || idx > e) return segment[node];
	if (s == e) return segment[node] = val;

	int mid = (s + e) / 2;
	return segment[node] = Update(idx, val, node * 2, s, mid) + Update(idx, val, node * 2 + 1, mid + 1, e);
}

int segmentTree::getIdx(int val, int node, int s, int e)
{
	if (s == e) return s;

	int sum = segment[node * 2];
	int mid = (s + e) / 2;

	if (sum >= val) return getIdx(val, node * 2, s, mid);
	else return getIdx(val - sum, node * 2 + 1, mid + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	segmentTree* stree = new segmentTree(candy, 1000000);

	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b;

		if (a == 1)
		{
			int idx = stree->getIdx(b, 1, 0, 999999);
			cout << idx + 1 << "\n";
			candy[idx]--;
			stree->Update(idx, candy[idx], 1, 0, 999999);
		}
		else
		{
			int c; cin >> c;

			candy[b - 1] += c;
			stree->Update(b - 1, candy[b - 1], 1, 0, 999999);
		}
	}

	delete stree;
}