#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001

int n, dist[MAX], check = 1, visited[MAX];
vector<pair<int, int>> vec[MAX];

void Input()
{
	cin >> n;

	int p, c, cost;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> p >> c >> cost;
		vec[p].push_back({ c, cost });
		vec[c].push_back({ p, cost });
	}
}

int DFS(int curr)
{
	visited[curr] = check;
	int ret = curr;
	dist[curr] = 0;

	for (int i = 0; i < vec[curr].size(); ++i)
	{
		if (visited[vec[curr][i].first] != check)
		{
			int next = DFS(vec[curr][i].first);

			if (dist[vec[curr][i].first] + vec[curr][i].second > dist[curr])
			{
				dist[curr] = dist[vec[curr][i].first] + vec[curr][i].second;
				ret = next;
			}
		}
	}

	return ret;
}

void Solve()
{
	int v2 = DFS(1);
	check++;
	int v3 = DFS(v2);

	cout << dist[v2];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}