// https://www.crocus.co.kr/613 참고.. ㅠㅠ 어렵네요

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 100001

int t, Sarr[MAX], group[MAX], team[MAX];

bool cmp(int x, int y)
{
	if (group[x] == group[y])
		return group[x + t] < group[y + t];
	return group[x] < group[y];
}

void Solve(string str)
{
	t = 1;
	int n = str.length();

	for (int i = 0; i < n; ++i)
	{
		Sarr[i] = i;
		group[i] = str[i] - 'a';
	}

	while (t <= n)
	{
		group[n] = -1;
		sort(Sarr, Sarr + n, cmp);
		team[Sarr[0]] = 0;

		for (int i = 1; i < n; ++i)
		{
			if (cmp(Sarr[i - 1], Sarr[i]))
				team[Sarr[i]] = team[Sarr[i - 1]] + 1;
			else
				team[Sarr[i]] = team[Sarr[i - 1]];
		}

		for (int i = 0; i < n; ++i)
			group[i] = team[i];

		t <<= 1;
	}

	for (int i = 0; i < n; ++i)
		cout << Sarr[i] << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	Solve(str);
}