#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 회전 정보 구조체
struct Rot_info {
	// x의 배수, 방향(0 시계, 1 반시계), 칸
	int x, d, k;
};

// 반지름, 원판에 적힌 숫자 개수, 회전 수
int N, M, T;

int board[51][51];		// 원판에 적힌 수 저장 배열
int tmpboard[51][51];	// 임시 저장 배열
Rot_info rot_info[51];	// 회전 정보 저장 배열
bool visited[51][51];		// 방문 체크 배열

int answer = 0;

void CopyArray(int aboard[][51], int bboard[][51])
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			aboard[i][j] = bboard[i][j];
		}
	}
}

void Rotation(int num, int dir, int cnt)
{
	CopyArray(tmpboard, board);

	if (dir == 0)	// 시계
	{
		for (int i = 0; i < M; ++i)
		{
			int m = (i + cnt) % M;
			tmpboard[num][m] = board[num][i];
		}
	}
	else	// 반시계
	{
		for (int i = 0; i < M; ++i)
		{
			int m = i - cnt;
			if (m < 0) m += M;
			tmpboard[num][m] = board[num][i];
		}
	}

	CopyArray(board, tmpboard);
}

bool BFS(int a, int b)
{
	queue<pair<int, int>> q;	// 인접하고 같은 수 찾을 큐
	vector<pair<int, int>> v;	// 인접하고 같은 수 위치 저장 벡터

	q.push({ a, b });
	v.push_back({ a, b });
	visited[a][b] = true;

	while (!q.empty())
	{
		int n = q.front().first;
		int m = q.front().second;
		q.pop();

		int left = m - 1;
		int right = m + 1;
		int up = n + 1;
		int down = n - 1;

		if (left < 0) left = M - 1;
		if (right >= M) right = right % M;

		// 왼쪽과 일치
		if (board[n][m] == board[n][left] && !visited[n][left])
		{
			visited[n][left] = true;
			q.push({ n, left });
			v.push_back({ n, left });
		}
		// 오른쪽과 일치
		if (board[n][m] == board[n][right] && !visited[n][right])
		{
			visited[n][right] = true;
			q.push({ n, right });
			v.push_back({ n, right });
		}
		// 위와 일치
		if (up <= N && board[n][m] == board[up][m] && !visited[up][m])
		{
			visited[up][m] = true;
			q.push({ up, m });
			v.push_back({ up, m });
		}
		// 아래와 일치
		if (down > 0 && board[n][m] == board[down][m] && !visited[down][m])
		{
			visited[down][m] = true;
			q.push({ down, m });
			v.push_back({ down, m });
		}
	}

	if (v.size() > 1)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			board[v[i].first][v[i].second] = 0;
		}

		return true;
	}
	else return false;

	v.clear();
}

pair<int, int> AvgAndCnt()
{
	pair<int, int> p;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			p.first += board[i][j];
			if (board[i][j]) p.second++;
		}
	}

	return p;
}

void Search()
{
	memset(visited, false, sizeof(visited));

	// 인접한 같은 수가 있는지 없는지 판별하는 변수
	bool flag = false;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// 방문하지 않았고, 0이 아니면
			if (!visited[i][j] && board[i][j])
			{
				if (BFS(i, j)) flag = true;
			}
		}
	}

	if (!flag)
	{
		pair<int, int> aac = AvgAndCnt();

		double avg = (double)(aac.first) / (double)(aac.second);

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (!board[i][j]) continue;

				if ((double)board[i][j] > avg) board[i][j]--;
				else if ((double)board[i][j] < avg) board[i][j]++;
			}
		}
	}

	answer = AvgAndCnt().first;
}

void Solve()
{
	for (int i = 1; i <= T; ++i)
	{
		int num = rot_info[i].x;
		int dir = rot_info[i].d;
		int cnt = rot_info[i].k;

		for (int j = num; j <= N; j = j + num)
		{
			Rotation(j, dir, cnt);	// 회전
		}

		Search();	// 탐색
	}

	cout << answer;
}

void Input()
{
	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= T; ++i)
	{
		cin >> rot_info[i].x >> rot_info[i].d >> rot_info[i].k;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}