#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int answer;

int board[505][505 * 2];		// ���� ��� �迭
int num[505][505 * 2];			// Ÿ�� ��ȣ ���� �迭
vector<int> adjList[505*505];	// ���� ����Ʈ
int path[505 * 505];			// �̵� ��� ����
bool visited[505 * 505];		// �湮�ߴ��� �Ǵ�

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// BFS�� path �迭�� �̵� ��� ����
void BFS()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int qf = q.front();
		q.pop();

		for (int i = 0; i < adjList[qf].size(); ++i)
		{
			int tmp = adjList[qf][i];

			if (visited[tmp]) continue;

			if (answer < tmp) answer = tmp;

			visited[tmp] = true;
			path[tmp] = qf;
			q.push(tmp);
		}
	}
}

// 4���� Ž���ϸ鼭 �� ���ư� �� ������ ��������Ʈ�� push_back
void MakeAdjList()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N * 2; ++j)
		{
			int curr = num[i][j];

			for (int k = 0; k < 4; ++k)
			{
				int newLeft = i + dx[k];
				int newRight = j + dy[k];

				if (newLeft < 0 || newRight < 0 || newLeft >= N || newRight >= N * N) continue;

				int next = num[newLeft][newRight];

				if (curr != next && board[i][j] == board[newLeft][newRight])
					adjList[curr].push_back(next);
			}
		}
	}
}

void Solve()
{
	MakeAdjList();
	BFS();

	vector<int> v;
	v.push_back(answer);

	// �Ųٷ� ��� Ž��
	while (path[answer])
	{
		answer = path[answer];
		v.push_back(answer);
	}

	// reverse�ؼ� ���
	cout << v.size() << "\n";
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i] << " ";
}

void Input()
{
	int idx = 1;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		// Ȧ���� 0���� �����ϴ� �� ����
		// Ȧ���� tmp 0, ¦���� tmp 1
		int tmp = (i % 2 == 0) ? 0 : 1;

		// �� �� �Է� ����
		for (int j = tmp; j < N * 2 - tmp; ++j)
		{
			// ��ķ� �Է� �ް�
			cin >> board[i][j];
			// Ÿ�� ��ȣ ����
			num[i][j] = idx;
			// Ÿ�� �����ʱ��� ������, Ÿ�� idx ����
			idx += (((j + tmp) % 2 == 0) ? 0 : 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}