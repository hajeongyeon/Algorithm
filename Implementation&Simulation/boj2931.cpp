// 2020.10.07 
// 백준 2931 가스관

#include <iostream>
using namespace std;

int n, m;
char board[26][26];
char pipe[7] = { '|', '-', '+', '1', '2', '3', '4' };
pair<int, int> start, dest;

// 상하좌우
int dx[4] = { -1, 1, 0, 0, }, dy[4] = { 0, 0, -1, 1 };

bool isRange(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

int FindDir(char p, int dir)
{
    int newDir = -1;

    switch (p)
    {
    case '|':
        if (dir == 0) newDir = 0;
        else if (dir == 1) newDir = 1;
        break;

    case '-':
        if (dir == 2) newDir = 2;
        else if (dir == 3) newDir = 3;
        break;

    case '+':
        if (dir == 0) newDir = 0;
        else if (dir == 1) newDir = 1;
        else if (dir == 2) newDir = 2;
        else if (dir == 3) newDir = 3;
        break;

    case '1':
        if (dir == 2) newDir = 1;
        else if (dir == 0) newDir = 3;
        break;

    case '2':
        if (dir == 1) newDir = 3;
        else if (dir == 2) newDir = 0;
        break;

    case '3':
        if (dir == 3) newDir = 0;
        else if (dir == 1) newDir = 2;
        break;

    case '4':
        if (dir == 3) newDir = 1;
        else if (dir == 0) newDir = 2;
        break;

    default:
        break;
    }

    return newDir;
}

void Solve()
{
    int cx = start.first, cy = start.second;
    int dir = -1;

    // 1. 모스크바에서 출발
    for (int i = 0; i < 4; ++i)
    {
        int tmpx = start.first + dx[i];
        int tmpy = start.second + dy[i];

        if (isRange(tmpx, tmpy) && board[tmpx][tmpy] != '.' && board[tmpx][tmpy] != 'Z')
        {
            cx = tmpx;
            cy = tmpy;
            dir = i;
            break;
        }
    }

    // 2. 막힐 때까지 탐색
    while (1)
    {
        if (board[cx][cy] == '.') break;

        dir = FindDir(board[cx][cy], dir);
        cx = cx + dx[dir];
        cy = cy + dy[dir];
    }

    // 3. 7가지 대입해서 자그레브에 도착할 수 있는지 판단
    for (int i = 0; i < 7; ++i)
    {
        int newdir = dir;
        int nx = cx, ny = cy;

        board[cx][cy] = pipe[i];

        while (1)
        {
            newdir = FindDir(board[nx][ny], newdir);

            if (newdir == -1) break;

            nx = nx + dx[newdir];
            ny = ny + dy[newdir];

            if (nx == dest.first && ny == dest.second)
            {
                cout << cx << " " << cy << " " << pipe[i];
                return;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 'M') start = make_pair(i, j);
            else if (board[i][j] == 'Z') dest = make_pair(i, j);
        }
    }

    Solve();
}
