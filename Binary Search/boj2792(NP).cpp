// 2020.06.23 23:15~
// 백준 2792
// 

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000000

int n, m, arr[300000];
long long large;

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i];

		if (large < arr[i]) large = arr[i];
	}
}

void Solve()
{
	sort(arr, arr + m);

	long long left = 0, right = MAX;
	long long answer = 0;

	while (left < right)
	{
		long long mid = (left + right) / 2;
		long long tmp = 0;

		for (int i = 0; i < n; ++i)
		{
			tmp += arr[i] / mid;

			if (arr[i] % mid != 0) tmp++;
		}

		if (tmp <= n)
		{
			answer = max(answer, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
