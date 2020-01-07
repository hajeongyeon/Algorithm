// 이진 탐색 사용

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;

int BinarySearch(int s, int e, int val)
{
	if (s > e) return 0;

	int mid = (s + e) / 2;

	if (vec[mid] > val) return BinarySearch(s, mid - 1, val);
	else if (vec[mid] == val) return 1;
	else return BinarySearch(mid + 1, e, val);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a; cin >> a;
		cout << BinarySearch(0, n - 1, a) << "\n";
	}
}