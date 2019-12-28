#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, start;

// end, val
vector<pair<int, int>> edge[300001];
// ��� ��忡������ �Ÿ��� �����ϴ� �迭 
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

		// ���� ��忡������ �ֺ��� �ִ� �ֵ��� ���� ����
		for (int i = 0; i < edge[currNode].size(); ++i)
		{
			int newV = dist[currNode] + edge[currNode][i].second;
			int pastV = dist[edge[currNode][i].first];

			// ���� ���κ��� ����� ������ ���������� ���� �Ÿ��� ������ �Ÿ��� ��
			// ������ ���� �� ũ�� �� ����
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