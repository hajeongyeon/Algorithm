#include <iostream>
#include <vector>
using namespace std;

int sbt[100001];
vector<int> tree[100001];

int DFS(int curr, int prev)
{
	sbt[curr] = 1;

	for (auto next : tree[curr])
	{
		if (prev == next) continue;

		sbt[curr] += DFS(next, curr);
	}

	return sbt[curr];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(R, 0);


	for (int i = 0; i < Q; ++i)
	{
		int u; cin >> u;
		cout << sbt[u] << "\n";
	}
}