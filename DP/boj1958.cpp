#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string str1, str2, str3;
int dp[101][101][101];

int max3(int a, int b, int c)
{
	if (a > b) return (a > c) ? a : c;
	else return (b > c) ? b : c;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> str1 >> str2 >> str3;

	int len1 = str1.length();
	int len2 = str2.length();
	int len3 = str3.length();

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			for (int k = 1; k <= len3; ++k)
			{
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
				{
					dp[i][j][k] = max(max3(dp[i - 1][j - 1][k], dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]), max3(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	cout << dp[len1][len2][len3];
}