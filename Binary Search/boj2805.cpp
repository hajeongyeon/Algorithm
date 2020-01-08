#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long tree[1000001];

long long Cal(long long len)
{
	long long result = 0;

	for (int i = 0; i < n; ++i)
		if (len < tree[i]) result += (tree[i] - len);

	return result;
}

long long BS(long long s, long long e, long long val)
{
	if (s > e) return e;

	long long mid = (s + e) / 2;
	long long result = Cal(mid);

	if (result == val) return mid;
	else if (result < val) return BS(s, mid - 1, val);
	else return BS(mid + 1, e, val);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long m, max_h = -1;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i];

		max_h = max(max_h, tree[i]);
	}

	cout << BS(0, max_h, m);
}