// https://www.weeklyps.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84 Âü°í

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 50005

int n, dist[MAX], dist2[MAX], far[MAX];
bool visited[MAX];
vector<pair<int, int>> vec[MAX];

void Input()
{
	cin >> n;

	int f, t, len;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> f >> t >> len;
		vec[f].push_back({ t, len });
		vec[t].push_back({ f, len });
	}
}

void distDFS(int curr)
{
	visited[curr] = true;
	dist[curr] = dist2[curr] = 0;

	for (int i = 0; i < vec[curr].size(); ++i)
	{
		int next = vec[curr][i].first;
		int cost = vec[curr][i].second;

		if (!visited[next])
		{
			distDFS(next);

			if (dist[next] + cost > dist[curr])
			{
				dist2[curr] = dist[curr];
				dist[curr] = dist[next] + cost;
			}
			else if (dist[next] + cost > dist2[curr])
				dist2[curr] = dist[next] + cost;
		}
	}
}

void farDFS(int curr, int pfar)
{
	visited[curr] = true;
	far[curr] = max(dist[curr], pfar);

	for (int i = 0; i < vec[curr].size(); ++i)
	{
		int next = vec[curr][i].first;
		int cost = vec[curr][i].second;

		if (!visited[next])
		{
			if (dist[next] + cost == dist[curr])
				farDFS(next, max(pfar + cost, dist2[curr] + cost));
			else
				farDFS(next, max(pfar + cost, dist[curr] + cost));
		}
	}
}

void Solve()
{
	distDFS(1);
	memset(visited, false, sizeof(visited));
	farDFS(1, 0);

	for (int i = 1; i <= n; ++i)
		cout << far[i] << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}