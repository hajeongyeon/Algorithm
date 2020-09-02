// 2020.09.02 19:13~19:50
// 백준 1654 랜선 자르기
// 이분탐색

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int k, n;
lli arr[10000], answer;

void Input()
{
	cin >> k >> n;
	for (int i = 0; i < k; ++i)
		cin >> arr[i];
}

void BinarySearch(lli s, lli e)
{
	if (s > e) return;

	lli mid = (s + e) / 2;
	lli cut = 0;

	for (int i = k - 1; i >= 0; --i)
	{
		if ((arr[i] / mid) == 0) break;
		else cut += (arr[i] / mid);
	}

	if (cut >= n)
	{
		answer = max(answer, mid);
		BinarySearch(mid + 1, e);
	}
	else
		BinarySearch(s, mid - 1);
}

void Solve()
{
	sort(arr, arr + k);

	BinarySearch(1, arr[k - 1]);
	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
