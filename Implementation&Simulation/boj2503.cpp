// 2020.06.13 00:29~01:16
// 백준 2503 숫자 야구
// Brute Force

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool arr[988];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, answer = 0, strike, ball;
	string num;

	cin >> n;

	// true로 설정
	memset(arr, true, sizeof(arr));

	for (int i = 123; i <= 987; ++i)
	{
		string tmp = to_string(i);

		// 십의 자리나 일의 자리가 0이면 false
		if (tmp[1] == '0' || tmp[2] == '0') arr[i] = false;
		// 백, 십, 일의 자리 중 중복이 있으면 false
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) arr[i] = false;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> num >> strike >> ball;

		for (int j = 123; j <= 987; ++j)
		{
			// 불가능한 수는 continue
			if (!arr[j]) continue;

			string tmp = to_string(j);
			int tmpstrike = 0, tmpball = 0;

			for (int a = 0; a < 3; ++a)
			{
				for (int b = 0; b < 3; ++b)
				{
					// 자리도 같고 숫자도 같으면 임의의 strike++
					if (a == b && num[a] == tmp[b]) tmpstrike++;
					// 자리는 다른데 숫자가 같으면 임의의 ball++
					if (a != b && num[a] == tmp[b]) tmpball++;
				}
			}

			// 다르면 그 숫자는 가능성이 있는 숫자에서 제외
			if (strike != tmpstrike || ball != tmpball) arr[j] = false;
		}
	}

	for (int i = 123; i <= 987; ++i)
		if (arr[i]) answer++;

	cout << answer;
}
