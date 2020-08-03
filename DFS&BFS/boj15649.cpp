// 2020.08.04 01:35~01:53
// 백준 15649 N과 M (1)
// DFS

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
bool visited[9];

void DFS(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < vec.size(); ++i)
			cout << vec[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i]) continue;

		visited[i] = true;
		vec.push_back(i);

		DFS(depth + 1);

		visited[i] = false;
		vec.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> n >> m;

	DFS(0);
}
