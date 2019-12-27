#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int seq[5001];
int dp[5005][5005];

int Palindrome(int s, int e)
{
	if (s >= e) return 0;

	int& ret = dp[s][e];
	if (ret != -1) return ret;

	if (seq[s] != seq[e])
	{
		ret = min(Palindrome(s + 1, e) + 1, Palindrome(s, e - 1) + 1);
	}
	else
		ret = Palindrome(s + 1, e - 1);

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	cout << Palindrome(0, N - 1);
}