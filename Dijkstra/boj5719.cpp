#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;

// V, ���� ����
vector<pair<int, int>> vec[501];
// �ִܰŸ��� �ش��ϴ� ������ trace�� ����
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
				// trace�� �ش��ϴ� ������ ����
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

	// cost�� vertex
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = -1 * pq.top().first;
		int currNode = pq.top().second;
		pq.pop();

		// �ּ� �Ÿ��� ���ϹǷ�
		if (dist[currNode] < cost) continue;

		for (int i = 0; i < vec[currNode].size(); ++i)
		{
			int neighbor = vec[currNode][i].first;
			int newDist = cost + vec[currNode][i].second;

			// �ִ� �Ÿ� Ž���� ���� ������ �������� ������ ����
			if (vec[currNode][i].second == -1) continue;

			// �ּ� ��� �߽߰� ������Ʈ
			if (dist[neighbor] > newDist)
			{
				dist[neighbor] = newDist;
				pq.push({ -1 * newDist, neighbor });

				// trace ����
				trace[neighbor].clear();
				trace[neighbor].push_back({ currNode, newDist });
			}
			// �ִ� �Ÿ� ã�� ������ trace ������Ʈ
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

		// ���ͽ�Ʈ��� �ִ� ��� ���ϱ�
		vector<int> dist = Dijkstra(S);
		// �ִ� ��� ����
		Delete(D);
		// ���� �ִ� ��� ���ϱ�
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