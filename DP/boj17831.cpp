#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int h, w, cnt, draw[205][205];
bool check[205][205];

char word[7] = "WAKJSD";
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void hextobin(int x, string str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        int hex = str[i] > 96 ? str[i] - 87 : str[i] - 48;

        for (int j = 4; j >= 1; --j)
        {
            draw[x][j + (4 * i)] = hex % 2;
            hex = hex / 2;
        }
    }
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    check[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w * 4 + 2) continue;
            if (check[nx][ny]) continue;

            if (!draw[nx][ny])
            {
                check[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

void DFS(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= h + 1 || ny >= w * 4 + 1) continue;
        if (check[nx][ny]) continue;

        if (!draw[nx][ny])
        {
            BFS(nx, ny);
            cnt++;
        }
        else
        {
            check[nx][ny] = true;
            DFS(nx, ny);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc = 1;
    while (cin >> h >> w)
    {
        if (h == 0 && w == 0) break;

        memset(draw, 0, sizeof(draw));
        memset(check, false, sizeof(check));

        string str;
        for (int i = 1; i <= h; ++i)
        {
            cin >> str;
            hextobin(i, str);
        }

        BFS(0, 0);

        vector<int> circle;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w * 4; ++j)
            {
                if (!check[i][j])
                {
                    cnt = 0;
                    check[i][j] = true;
                    DFS(i, j);
                    circle.push_back(cnt);
                }
            }
        }

        string answer;
        for (int i = 0; i < circle.size(); ++i)
            answer.push_back(word[circle[i]]);

        sort(answer.begin(), answer.end());

        cout << "Case " << tc++ << ": " << answer << "\n";
    }
}