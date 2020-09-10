// 2020.09.10 20:22~
// 백준 9466 텀 프로젝트
// DFS

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100001;

int n, cnt;
int student[MAX];
bool visited[MAX], done[MAX];

void Init()
{
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    memset(done, 0, sizeof(done));
}

void DFS(int idx)
{
    visited[idx] = true;

    int next = student[idx];

    if (!visited[next]) DFS(next);
    else if (!done[next])
    {
        for (int i = next; i != idx; i = student[i]) cnt++;
        cnt++;
    }

    done[idx] = true;
}

void Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i]) continue;
        DFS(i);
    }

    cout << n - cnt << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc; cin >> tc;

    for (int t = 0; t < tc; ++t)
    {
        Init();

        cin >> n;
        
        for (int i = 1; i <= n; ++i)
            cin >> student[i];

        Solve();
    }
}
