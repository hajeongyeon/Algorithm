#include <iostream>
#include <queue>
using namespace std;

struct info {
	int x, y, z;
};

int m, n, h;

int box[100][100][100];
queue<info> ripe;

int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

bool allRipeCheck()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (box[i][j][k] == 0) return false;
			}
		}
	}

	return true;
}

int BFS()
{
	int day = 0;

	while (!ripe.empty())
	{
		int tomatoSize = ripe.size();

		for (int t = 0; t < tomatoSize; ++t)
		{
			int x = ripe.front().x;
			int y = ripe.front().y;
			int z = ripe.front().z;
			ripe.pop();

			for (int i = 0; i < 6; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;

				if (!box[nz][ny][nx])
				{
					box[nz][ny][nx] = 1;
					ripe.push({ nx, ny, nz });
				}
			}

			if (ripe.size() == 0)
			{
				if (allRipeCheck()) return day;
				else return -1;
			}
		}

		day++;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> m >> n >> h;

	bool isRipe = true;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> box[i][j][k];
				
				if (box[i][j][k] == 0) isRipe = false;
				else if(box[i][j][k] == 1) ripe.push({ k, j, i });
			}
		}
	}

	if (!isRipe) cout << BFS();
	else cout << "0";
}