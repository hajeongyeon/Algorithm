#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, start;

// end, val
vector<pair<int, int>> edge[300001];
// 출발 노드에서부터 거리를 저장하는 배열 
int dist[20001];

void Dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int currNode = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		// 현재 노드에서부터 주변에 있는 애들의 값을 갱신
		for (int i = 0; i < edge[currNode].size(); ++i)
		{
			int newV = dist[currNode] + edge[currNode][i].second;
			int pastV = dist[edge[currNode][i].first];

			// 현재 노드로부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 비교
			// 기존의 것이 더 크면 값 갱신
			if (newV < pastV)
			{
				dist[edge[currNode][i].first] = newV;
				pq.push({ -1 * newV, edge[currNode][i].first });
			}
		}
	}
}

int main(void)
{
	cin >> V >> E >> start;

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; ++i) dist[i] = 1e9;
	dist[start] = 0;

	Dijkstra();

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] != 1e9) cout << dist[i];
		else cout << "INF";
		cout << "\n";
	}
}