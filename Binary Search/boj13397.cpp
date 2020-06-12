#include <iostream>
using namespace std;

int n, m, arr[5000];

int psearch(int itv)
{
	int min = arr[0], max = arr[0], cnt = 1;

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
		if (max - min > itv)
		{
			min = max = arr[i];
			cnt++;
		}
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int s = 0, e = 9999;

	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (psearch(mid) > m) s = mid + 1;
		else e = mid - 1;
	}

	cout << s;
}