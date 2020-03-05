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

	int lcslen = 0, max, len1 = str1.length();
	for (int i = 1; i < str2.length(); ++i)
	{
		max = 0;
		dp[i][0] = 0;

		for (int j = 1; j < len1; ++j)
		{
			if (str1[j] == str2[i])
			{
				max = dp[i - 1][j - 1] + 1;
				dp[i][j] = max;
			}
			else
			{
				if (dp[i - 1][j] < dp[i][j - 1])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		if (lcslen < max) lcslen = max;
	}
	cout << lcslen << "\n";

	int tmp = lcslen - 1;
	string lcsstr = "";

	for (int i = str2.length() - 1; i > 0; --i)
	{
		for (int j = len1 - 1; j > 0; --j)
		{
			if (dp[i][j] == lcslen && dp[i][j - 1] == tmp && dp[i - 1][j] == tmp && dp[i - 1][j - 1] == tmp)
			{
				lcslen--;
				tmp--;
				lcsstr = str2[i] + lcsstr;
				len1 = j;
				break;
			}
		}
	}

	cout << lcsstr;
}