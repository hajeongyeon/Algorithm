#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct info {
    int x, y, dist;
};

int n, m;
char board[50][50];
bool visited[50][50];

int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

int Solve()
{
    int ans = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] != 'L') continue;

            memset(visited, false, sizeof(visited));

            queue<info> q;
            q.push({ i, j, 0 });
            visited[i][j] = true;

            while (!q.empty())
            {
                int x = q.front().x;
                int y = q.front().y;
                int d = q.front().dist;
                q.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (visited[nx][ny] || board[nx][ny] == 'W') continue;

                    q.push({ nx, ny, d + 1 });
                    visited[nx][ny] = true;

                    ans = ans < d + 1 ? d + 1 : ans;
                }
            }
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    cout << Solve();
}
