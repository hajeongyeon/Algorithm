#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, l;
	cin >> n >> l;

	deque<pair<int, int>> d;
	int m = 1e9;

	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;

		if (!d.empty() && d.front().second <= i - l)
			d.pop_front();

		while (!d.empty() && d.back().first >= num)
			d.pop_back();

		d.push_back({ num, i });

		cout << d.front().first << " ";
	}
}
