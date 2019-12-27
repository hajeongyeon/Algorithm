#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int num[2005];
int dp[2005][2005];

int Palindrome(int s, int e)
{
	if (s >= e) return 1;

	int& ret = dp[s][e];
	if (ret != -1) return ret;

	if (num[s] != num[e]) return 0;

	return ret = Palindrome(s + 1, e - 1);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N, M;
	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> num[i];

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		if (Palindrome(s, e)) cout << "1\n";
		else cout << "0\n";
	}
}