#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[50][50];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1, 0, 1, -1, 1, -1 , 0, 1 };

int Solve()
{
    int answer = 0;
    bool visited[50][50] = { 0, };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] || board[i][j] == 0) continue;

            queue<pair<int, int>> q;
            q.push({ i, j });
            visited[i][j] = true;
            answer++;

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 8; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (visited[nx][ny] || board[nx][ny] == 0) continue;

                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (1)
    {
        cin >> m >> n;

        if (n == 0 && m == 0) break;

        memset(board, 0, sizeof(board));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> board[i][j];

        cout << Solve() << "\n";
    }
}
