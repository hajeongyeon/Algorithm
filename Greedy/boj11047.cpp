// 2020.08.05 20:30~20:38
// 백준 11047 동전 0
// 그리디

#include <iostream>
using namespace std;

int n, k, arr[10], answer;

void Solve()
{
	for (int i = n - 1; i >= 0; --i)
	{
		if (k == 0) break;
		if (arr[i] > k) continue;

		int tmp = k / arr[i];
		answer += tmp;
		k -= (arr[i] * tmp);
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	Solve();
}
