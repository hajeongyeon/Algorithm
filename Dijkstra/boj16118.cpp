#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> route[100001];
int fox_dist[4001], wolf_dist[4001][2];

void fox_Dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int dist = -1 * pq.top().first;
		pq.pop();

		if (fox_dist[curr] != dist) continue;
		for (int i = 0; i < route[curr].size(); ++i)
		{
			int n = fox_dist[curr] + route[curr][i].second;
			int p = fox_dist[route[curr][i].first];

			if (n < p)
			{
				fox_dist[route[curr][i].first] = n;
				pq.push({ -1 * n, route[curr][i].first });
			}
		}
	}
}

void wolf_Dijkstra()
{
	priority_queue<pair<int, pair<int, bool>>> pq;
	pq.push({ 0, { 1, true } });

	while (!pq.empty())
	{
		int curr = pq.top().second.first;
		int dist = -1 * pq.top().first;
		bool isFast = pq.top().second.second;
		pq.pop();

		if (wolf_dist[curr][isFast] != dist) continue;

		for (int i = 0; i < route[curr].size(); ++i)
		{
			int n;
			int p = wolf_dist[route[curr][i].first][!isFast];

			if (isFast)
				n = wolf_dist[curr][isFast] + (route[curr][i].second / 2);
			else
				n = wolf_dist[curr][isFast] + (route[curr][i].second * 2);

			if (n < p)
			{
				wolf_dist[route[curr][i].first][!isFast] = n;
				pq.push({ -1 * n, { route[curr][i].first, !isFast } });
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
		int a, b;
		int d;
		cin >> a >> b >> d;

		route[a].push_back({ b, d * 2 });
		route[b].push_back({ a, d * 2 });
	}

	for (int i = 1; i <= n; ++i)
	{
		fox_dist[i] = 2e9;
		wolf_dist[i][0] = 2e9;
		wolf_dist[i][1] = 2e9;
	}

	fox_dist[1] = 0;
	wolf_dist[1][1] = 0;

	fox_Dijkstra();
	wolf_Dijkstra();

	int answer = 0;

	for (int i = 2; i <= n; ++i)
	{
		int tmp = 0;
		if (wolf_dist[i][0] < wolf_dist[i][1]) tmp = wolf_dist[i][0];
		else tmp = wolf_dist[i][1];
		if (tmp > fox_dist[i]) answer++;
	}

	cout << answer;
}