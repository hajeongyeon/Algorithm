#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int BSearch(int s, int e, int val)
{
	if (s > e) return -1;
	else if (s == e)
	{
		if (val == arr[s]) return s;
		else return -1;
	}

	int mid = (s + e) / 2;

	if (arr[mid] == val) return 1;
	else if (arr[mid] > val) return BSearch(s, mid - 1, val);
	else return BSearch(mid + 1, e, val);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, tmp; 
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		auto lower = lower_bound(arr, arr + n, tmp);
		auto upper = upper_bound(arr, arr + n, tmp);

		cout << upper - lower << " ";
	}
}