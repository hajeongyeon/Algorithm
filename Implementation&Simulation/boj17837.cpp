#include <iostream>
#include <vector>
using namespace std;

struct h_info {
	int x, y, d, h;
};

int n, k, board[12][12];
h_info horse[10];
vector<int> ground[12][12];

void Solve()
{
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	bool check = false;
	int turn = 0;

	while (turn < 1000)
	{
		turn++;

		for (int i = 0; i < k; ++i)
		{
			int x = horse[i].x;
			int y = horse[i].y;
			int d = horse[i].d;
			int h = horse[i].h;
			
			int nx = x + dx[d];
			int ny = y + dy[d];

			int s = ground[x][y].size();

			// ü������ ����ų� �Ķ����� ���
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2)
			{
				if (horse[i].d < 2) horse[i].d = (horse[i].d + 1) % 2;
				else horse[i].d = (horse[i].d + 1) % 2 + 2;
				nx = x + dx[horse[i].d];
				ny = y + dy[horse[i].d];
			}

			// �ٵ� �� ������ �� �Ķ����̸� ����
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2) continue;

			// �������� ���
			if (board[nx][ny] == 1)
			{
				for (int j = h; j < s; ++j)
				{
					int b = ground[x][y].back();
					ground[nx][ny].push_back(b);
					horse[b].h = ground[nx][ny].size() - 1;
					horse[b].x = nx;
					horse[b].y = ny;
					ground[x][y].pop_back();
				}
			}
			// ����� ���
			else if(board[nx][ny] == 0)
			{
				for (int j = h; j < s; ++j)
				{
					ground[nx][ny].push_back(ground[x][y][j]);
					horse[ground[x][y][j]].h = ground[nx][ny].size() - 1;;
					horse[ground[x][y][j]].x = nx;
					horse[ground[x][y][j]].y = ny;
				}
				for (int j = h; j < s; ++j)
					ground[x][y].pop_back();
			}

			if (ground[nx][ny].size() >= 4)
			{
				check = true;
				break;
			}
		}

		if (check) break;
	}

	if (turn == 1000) cout << "-1";
	else cout << turn;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	int a, b, c;
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b >> c;
		horse[i] = { --a, --b, --c, 0 };
		ground[a][b].push_back(i);
	}

	Solve();
}