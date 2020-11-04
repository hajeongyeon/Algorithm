#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
    int r, c, m, s, d;
};

int n, m, k;

int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<info> vec[50][50];
queue<info> q;

void Solve()
{
    for (int turn = 0; turn < k; ++turn)
    {
        // 방향 d로 속력 s만큼 이동
        while (!q.empty())
        {
            int qsize = q.size();
            while (qsize--)
            {
                info tmp = q.front();
                q.pop();

                int nr = (tmp.r + (dr[tmp.d] * tmp.s)) % n;
                int nc = (tmp.c + (dc[tmp.d] * tmp.s)) % n;

                if (nr < 0) nr += n;
                if (nc < 0) nc += n;

                vec[nr][nc].push_back({ nr, nc, tmp.m, tmp.s, tmp.d });
            }
        }

        // 이동이 모두 끝난 후 2개 이상의 파이어볼이 있는 칸에서 행동
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (vec[j][k].empty()) continue;
                if (vec[j][k].size() == 1)
                    q.push(vec[j][k][0]);
                else
                {
                    int tmpm = 0, tmps = 0, oddd = 0;
                    for (int l = 0; l < vec[j][k].size(); ++l)
                    {
                        tmpm += vec[j][k][l].m;
                        tmps += vec[j][k][l].s;

                        if (vec[j][k][l].d % 2 == 1) oddd++;
                    }

                    // 4개로 쪼갬
                    tmpm /= 5;
                    tmps /= vec[j][k].size();

                    int newdir = 0;
                    if (oddd != vec[j][k].size() && oddd != 0) newdir = 1;

                    if (tmpm)
                    {
                        for (int l = 0; l < 4; ++l)
                        {
                            q.push({ j, k, tmpm, tmps, newdir });
                            newdir += 2;
                        }
                    }
                }

                vec[j][k].clear();
            }
        }
    }

    int answer = 0;
    while (!q.empty())
    {
        answer += q.front().m;
        q.pop();
    }

    cout << answer;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        q.push({ a - 1, b - 1, c, d, e });
    }

    Solve();
}
