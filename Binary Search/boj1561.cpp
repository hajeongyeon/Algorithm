#include <iostream>
using namespace std;

long long n;
int m, Time[10001];

long long binarySearch()
{
	// end 범위 ㅠㅠ
	long long s = 0, e = 2e9 * 30;
	long long result = 0;

	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long children = m;

		for (int i = 0; i < m; ++i)
			children += mid / Time[i];

		if (children >= n)
		{
			result = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	return result;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> Time[i];

	if (n <= m)
	{
		cout << n;
		return 0;
	}

	// 마지막 애가 탑승한 시간
	long long last = binarySearch();
	long long ride = m;

	// (last - 1)분까지 몇 명이 탔는지
	for (int i = 0; i < m; ++i)
		ride += (last - 1) / Time[i];

	for (int i = 0; i < m; ++i)
	{
		if (!(last % Time[i])) ride++;

		if (ride == n)
		{
			cout << i + 1;
			break;
		}
	}
}