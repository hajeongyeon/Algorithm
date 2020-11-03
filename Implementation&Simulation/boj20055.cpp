#include <iostream>
using namespace std;

struct info {
    int dur;
    bool isRobot;
};

int n, k;
info belt[200];

void Solve()
{
    int answer = 0;

    while (1)
    {
        // 1. 벨트 회전
        info tmp = belt[2 * n - 1];
        for (int i = 2 * n - 1; i >= 1; --i)
            belt[i] = belt[i - 1];
        belt[0] = tmp;

        // 2. 로봇 이동
        for(int i = n - 1; i >= 0; --i)
        {
            // 로봇이 없으면 continue
            if (!belt[i].isRobot) continue;
        
            // (1) 로봇이 내려가는 위치면 내림
            if (i == n - 1)
            {
                belt[i].isRobot = false;
                continue;
            }
        
            // (2) 이동하려는 칸에 로봇이 없고, 내구도가 1 이상이면 이동
            if (!belt[i + 1].isRobot && belt[i + 1].dur > 0)
            {
                if(i != n - 2)
                    belt[i + 1].isRobot = true;

                belt[i + 1].dur--;
                belt[i].isRobot = false;
            }
        }
        
        // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올림
        if (!belt[0].isRobot && belt[0].dur)
        {
            belt[0].dur--;
            belt[0].isRobot = true;
        }
        
        answer++;
        
        // 4. 내구도가 0인 칸의 개수가 K개 이상이면 종료
        int zero = 0;
        for (int i = 0; i < 2 * n; ++i)
            if (belt[i].dur == 0) zero++;
        
        if (zero >= k)
        {
            cout << answer;
            return;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n * 2; ++i)
    {
        int a; cin >> a;
        belt[i] = { a, false };
    }

    Solve();
}
