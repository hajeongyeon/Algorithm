#include <iostream>
using namespace std;

int n;
int arr[33][33];
long long dp[33][33][3];

void Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!arr[i][j + 1]) dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            if (!arr[i + 1][j]) dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            if (!arr[i + 1][j + 1] && !arr[i][j + 1] && !arr[i + 1][j]) 
                dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    dp[1][2][0] = 1;

    Solve();
}
