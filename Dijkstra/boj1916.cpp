#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e;
vector<pair<int, int>> edge[100001];
int dist[1001];

void Dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < edge[curr].size(); ++i)
		{
			int nd = dist[curr] + edge[curr][i].second;
			int p = dist[edge[curr][i].first];

			if (nd < p)
			{
				dist[edge[curr][i].first] = nd;
				pq.push({ -1 * nd, edge[curr][i].first });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;

		edge[u].push_back({ v, c });
	}
	cin >> s >> e;

	for (int i = 1; i <= n; ++i) dist[i] = 1e9;
	dist[s] = 0;

	Dijkstra();

	cout << dist[e];
}