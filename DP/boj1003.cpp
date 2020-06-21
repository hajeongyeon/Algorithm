// 2020.06.21 22:58~23:13
// 백준 1003 피보나치 함수
// DP

#include <iostream>
using namespace std;

int t, arr[41][2];

void Solve()
{
	// 메모이제이션
	arr[0][0] = 1, arr[0][1] = 0;
	arr[1][0] = 0, arr[1][1] = 1;

	// 피보나치의 특성을 이용
	for (int i = 2; i <= 40; ++i)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	cin >> t;

	for (int tc = 0; tc < t; ++tc)
	{
		int n; cin >> n;
		cout << arr[n][0] << " " << arr[n][1] << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Solve();
}
