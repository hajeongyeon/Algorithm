#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> vec[1001];
bool visited[1001];

void DFS(int c)
{
	visited[c] = true;
	cout << c << " ";

	for (int i = 0; i < vec[c].size(); ++i)
		if (!visited[vec[c][i]]) DFS(vec[c][i]);
}

void BFS()
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";

		for (int i = 0; i < vec[tmp].size(); ++i)
		{
			if (!visited[vec[tmp][i]])
			{
				visited[vec[tmp][i]] = true;
				q.push(vec[tmp][i]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
		sort(vec[i].begin(), vec[i].end());

	DFS(v);
	cout << "\n";
	memset(visited, false, sizeof(visited));

	BFS();
}