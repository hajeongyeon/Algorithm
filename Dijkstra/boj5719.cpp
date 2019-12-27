#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;

// V, 도로 길이
vector<pair<int, int>> vec[501];
// 최단거리에 해당하는 정점을 trace에 넣음
vector<pair<int, int>> trace[501];
bool visited[501][501];

void Delete(int dest)
{
	queue<int> q;
	q.push(dest);

	while (!q.empty())
	{
		int currNode = q.front();
		q.pop();

		for (int i = 0; i < trace[currNode].size(); ++i)
		{
			int neighbor = trace[currNode][i].first;

			if (visited[currNode][neighbor]) continue;

			for (int j = 0; j < vec[neighbor].size(); ++j)
			{
				// trace에 해당하는 정점들 삭제
				if (vec[neighbor][j].first == currNode)
					vec[neighbor][j].second = -1;
			}

			q.push(neighbor);
		}
	}
}

vector<int> Dijkstra(int start)
{
	vector<int> dist(N, 1e9);
	dist[start] = 0;

	// cost와 vertex
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = -1 * pq.top().first;
		int currNode = pq.top().second;
		pq.pop();

		// 최소 거리를 원하므로
		if (dist[currNode] < cost) continue;

		for (int i = 0; i < vec[currNode].size(); ++i)
		{
			int neighbor = vec[currNode][i].first;
			int newDist = cost + vec[currNode][i].second;

			// 최단 거리 탐색을 위해 삭제된 정점간의 간선을 무시
			if (vec[currNode][i].second == -1) continue;

			// 최소 경로 발견시 업데이트
			if (dist[neighbor] > newDist)
			{
				dist[neighbor] = newDist;
				pq.push({ -1 * newDist, neighbor });

				// trace 갱신
				trace[neighbor].clear();
				trace[neighbor].push_back({ currNode, newDist });
			}
			// 최단 거리 찾을 때마다 trace 업데이트
			else if (dist[neighbor] == newDist)
				trace[neighbor].push_back({ currNode, newDist });
		}
	}

	return dist;
}

void Solve()
{
	while (1)
	{
		int S, D;

		memset(visited, false, sizeof(visited));
		memset(vec, 0, sizeof(vec));
		memset(trace, 0, sizeof(trace));

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		cin >> S >> D;

		for (int i = 0; i < M; ++i)
		{
			int u, v, p;
			cin >> u >> v >> p;
			vec[u].push_back({ v, p });
		}

		// 다익스트라로 최단 경로 구하기
		vector<int> dist = Dijkstra(S);
		// 최단 경로 삭제
		Delete(D);
		// 거의 최단 경로 구하기
		vector<int> result = Dijkstra(S);

		if (result[D] == 1e9)
			cout << "-1" << endl;
		else
			cout << result[D] << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Solve();
}