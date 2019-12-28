#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int answer;

int board[505][505 * 2];		// 인접 행렬 배열
int num[505][505 * 2];			// 타일 번호 저장 배열
vector<int> adjList[505*505];	// 인접 리스트
int path[505 * 505];			// 이동 경로 저장
bool visited[505 * 505];		// 방문했는지 판단

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// BFS로 path 배열에 이동 경로 저장
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

// 4방향 탐색하면서 더 나아갈 수 있으면 인접리스트에 push_back
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

	// 거꾸로 경로 탐색
	while (path[answer])
	{
		answer = path[answer];
		v.push_back(answer);
	}

	// reverse해서 출력
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
		// 홀수가 0부터 시작하는 것 유의
		// 홀수면 tmp 0, 짝수면 tmp 1
		int tmp = (i % 2 == 0) ? 0 : 1;

		// 한 줄 입력 받음
		for (int j = tmp; j < N * 2 - tmp; ++j)
		{
			// 행렬로 입력 받고
			cin >> board[i][j];
			// 타일 번호 저장
			num[i][j] = idx;
			// 타일 오른쪽까지 왔으면, 타일 idx 증가
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