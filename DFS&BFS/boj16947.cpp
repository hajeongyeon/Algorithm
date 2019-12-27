#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> station[3001];
bool visited[3001];
bool cycle;
bool cycleStation[3001];
int dist[3001];

void FindDist(int n)
{
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({n, 0});
	visited[n] = true;

	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// 뻗어나간 방향이 순환선인지
		if (cycleStation[num])
		{
			dist[n] = cnt;
			return;
		}

		for (int i = 0; i < station[num].size(); ++i)
		{
			if (visited[station[num][i]]) continue;

			// 연결된 부분과 거리를 queue에 push
			visited[station[num][i]] = true;
			q.push({ station[num][i], cnt + 1 });
		}
	}
}

void FindCycle(int start, int curr, int cnt)
{
	// 순환이면
	if (start == curr && cnt >= 2)
	{
		cycle = true;
		return;
	}

	visited[curr] = true;

	for (int i = 0; i < station[curr].size(); ++i)
	{
		// 방문하지 않았으면
		if (!visited[station[curr][i]])
			FindCycle(start, station[curr][i], cnt + 1);
		// 방문했으면
		else
		{
			// 순환이면
			if(station[curr][i] == start && cnt >= 2)
				FindCycle(start, station[curr][i], cnt);
		}

		if (cycle) return;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	// 연결 정보 입력 받아서 station vector에 저장
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		station[a].push_back(b);
		station[b].push_back(a);
	}

	// 순환선인지 판단
	for (int i = 1; i <= N; ++i)
	{
		memset(visited, 0, sizeof(visited));
		cycle = false;

		FindCycle(i, i, 0);

		// 순환선이면 cycleStation true
		if (cycle) cycleStation[i] = true;
	}

	// 순환선으로부터 거리 구하기
	for (int i = 1; i <= N; ++i)
	{
		// 순환선이면 거리 0
		if (cycleStation[i])
			dist[i] = 0;
		// 순환선이 아니라면 탐색
		else
			FindDist(i);
	}

	for (int i = 1; i <= N; ++i)
		cout << dist[i] << " ";
}