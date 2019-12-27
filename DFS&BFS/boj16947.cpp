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

		// ����� ������ ��ȯ������
		if (cycleStation[num])
		{
			dist[n] = cnt;
			return;
		}

		for (int i = 0; i < station[num].size(); ++i)
		{
			if (visited[station[num][i]]) continue;

			// ����� �κа� �Ÿ��� queue�� push
			visited[station[num][i]] = true;
			q.push({ station[num][i], cnt + 1 });
		}
	}
}

void FindCycle(int start, int curr, int cnt)
{
	// ��ȯ�̸�
	if (start == curr && cnt >= 2)
	{
		cycle = true;
		return;
	}

	visited[curr] = true;

	for (int i = 0; i < station[curr].size(); ++i)
	{
		// �湮���� �ʾ�����
		if (!visited[station[curr][i]])
			FindCycle(start, station[curr][i], cnt + 1);
		// �湮������
		else
		{
			// ��ȯ�̸�
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

	// ���� ���� �Է� �޾Ƽ� station vector�� ����
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		station[a].push_back(b);
		station[b].push_back(a);
	}

	// ��ȯ������ �Ǵ�
	for (int i = 1; i <= N; ++i)
	{
		memset(visited, 0, sizeof(visited));
		cycle = false;

		FindCycle(i, i, 0);

		// ��ȯ���̸� cycleStation true
		if (cycle) cycleStation[i] = true;
	}

	// ��ȯ�����κ��� �Ÿ� ���ϱ�
	for (int i = 1; i <= N; ++i)
	{
		// ��ȯ���̸� �Ÿ� 0
		if (cycleStation[i])
			dist[i] = 0;
		// ��ȯ���� �ƴ϶�� Ž��
		else
			FindDist(i);
	}

	for (int i = 1; i <= N; ++i)
		cout << dist[i] << " ";
}