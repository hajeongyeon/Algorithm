#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k = -1, c = 0;
	cin >> n;
	m = n;

	while (1)
	{
		c++;
		int tmp = (m / 10) + (m % 10);
		k = ((m % 10) * 10) + (tmp % 10);
		if (n == k) break;
		m = k;
	}

	cout << c;
}