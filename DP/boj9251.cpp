#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	int len1 = str1.length(), len2 = str2.length();

	int lcs = 0, max;
	for (int i = 1; i < len2; ++i)
	{
		max = 0;
		dp[i][0] = 0;

		for (int j = 1; j < len1; ++j)
		{
			if (str2[i] == str1[j])
			{
				max = dp[i - 1][j - 1] + 1;
				dp[i][j] = max;
			}
			else
			{
				if (dp[i][j - 1] > dp[i - 1][j])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		if (lcs < max) lcs = max;
	}

	cout << lcs;
}