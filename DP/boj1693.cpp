// 구글, 질문검색 다 참고해서 풀었습니다.. ㅠ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

int n, dp[MAX][20];
vector<int> vec[MAX];

int DP(int curr, int prev, int color)
{
	int& ret = dp[curr][color];
	if (ret) return ret;

	int sum = 0;
	for (int i = 0; i < vec[curr].size(); ++i)
	{
		int tmpmin = 1e9;

		if (vec[curr][i] != prev)
		{
			for (int next = 1; next <= 18; ++next)
			{
				if (color != next)
					tmpmin = min(tmpmin, DP(vec[curr][i], curr, next));
			}
			sum += tmpmin;
		}
	}

	return ret = sum + color;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	int answer = 1e9;
	for (int i = 1; i <= 18; ++i)
		answer = min(answer, DP(1, 0, i));

	cout << answer;
}