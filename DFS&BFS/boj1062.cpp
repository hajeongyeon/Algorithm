#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
vector<string> vec;
int answer;

void Solve(int cnt, int bit, int idx)
{
	// 종료 조건
	if (idx > 26) return;
	if (cnt == k)
	{
		int tmp = 0;
		for (int i = 0; i < n; ++i)
		{
			string str = vec[i];
			bool flag = true;

			for (int j = 0; j < str.length(); ++j)
			{
				if (((1 << (str[j] - 'a')) & bit) > 0) continue;

				flag = false;
				break;
			}

			if (flag) tmp++;
		}
		answer = max(answer, tmp);
		return;
	}

	// 재귀 조건
	if (idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19)
		Solve(cnt, bit, idx + 1);
	else
	{
		if (cnt <= k)
			Solve(cnt + 1, bit | (1 << idx), idx + 1);

		Solve(cnt, bit, idx + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	k -= 5;
	if (k < 0)
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		string str; cin >> str;
		vec.push_back(str);
	}

	int bit = 0;
	bit |= (1 << ('a' - 'a'));
	bit |= (1 << ('n' - 'a'));
	bit |= (1 << ('t' - 'a'));
	bit |= (1 << ('i' - 'a'));
	bit |= (1 << ('c' - 'a'));

	Solve(0, bit, 0);

	cout << answer;
}