#include <iostream>
using namespace std;

int n, a, b, ans;
int node[101][101];
bool visited[101];

void DFS(int s, int e, int cnt)
{
    if (s == e)
    {
        ans = cnt;
        return;
    }

    visited[s] = true;

    for (int i = 1; i <= n; ++i)
    {
        if (node[s][i] == 0 || visited[i]) continue;
        
        DFS(i, e, cnt + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    int cnt; cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        int x, y; cin >> x >> y;

        node[x][y] = node[y][x] = 1;
    }

    DFS(a, b, 0);

    if (ans == 0) ans = -1;

    cout << ans;
}
