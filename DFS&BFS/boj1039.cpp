#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

string str;
int dp[1000001][11];

void swap(int a, int b)
{
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}

int DFS(int cnt)
{
	int num = stoi(str);

	// 종료 조건
	if (cnt == 0) return num;

	if (dp[num][cnt] != 0) return dp[num][cnt];

	int MAX = -1;

	// 재귀 조건
	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = i + 1; j < str.length(); ++j)
		{
			if (i == 0 && str[j] == '0') continue;

			swap(i, j);
			MAX = max(MAX, DFS(cnt - 1));
			swap(j, i);
		}
	}

	return dp[num][cnt] = MAX;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	str = to_string(n);

	cout << DFS(k);
}