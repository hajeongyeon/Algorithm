#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<pair<int, int>> road[1001];
priority_queue<int> dist[1001];

void Dijkstra()
{
	dist[1].push(0);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		for (auto i : road[curr])
		{
			int n = i.first;
			int nd = i.second + cost;

			if (dist[n].size() < k)
			{
				dist[n].push(nd);
				pq.push({ -1 * nd, n });
			}
			else if (dist[n].top() > nd)
			{
				dist[n].pop();
				dist[n].push(nd);
				pq.push({ -1 * nd, n });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		road[a].push_back({ b, c });
	}

	Dijkstra();

	for (int i = 1; i <= n; ++i)
	{
		if (dist[i].size() == k)
			cout << dist[i].top() << "\n";
		else
			cout << "-1\n";
	}
}