#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long x, y, z;

	cin >> x >> y;

	z = y * 100 / x;

	if (z == 99 || z == 100)
	{
		cout << "-1";
		return 0;
	}

	long long a = (x * (z + 1) - (100 * y));
	long long b = 99 - z;

	long long answer = 0;

	if (a % b != 0) answer = a / b + 1;
	else answer = a / b;

	cout << answer;
}