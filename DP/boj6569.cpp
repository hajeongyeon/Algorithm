#include <iostream>
#include <cstring>
using namespace std;

int h, w;
long long dp[11 * 11][1 << 11];

long long DP(int num, int status)
{
    if (num == h * w && !status) return 1;
    if (num >= h * w) return 0;
    if (dp[num][status] != -1) return dp[num][status];

    long long &ret = dp[num][status];
    ret = 0;

    if (status & 1)
        ret = DP(num + 1, status >> 1);
    else
    {
        ret = DP(num + 1, (status >> 1 | 1 << w - 1));

        if (((num % w) != (w - 1)) && !(status & 2))
            ret += DP(num + 2, status >> 2);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (cin >> h >> w)
    {
        if (h == 0 && w == 0) break;

        memset(dp, -1, sizeof(dp));

        cout << DP(0, 0) << "\n";
    }
}
