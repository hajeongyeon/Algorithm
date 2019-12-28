#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int x, k;
	bool arr[65] = { 0, };
	long long candidate = 1, answer = 0;

	cin >> x >> k;

	for (int i = 0; x > 0; x /= 2, i++) arr[i] = x % 2;

	int idx = 0;
	while(k > 0)
	{
		if (!arr[idx])
		{
			if (k % 2) answer += candidate;
			k /= 2;
		}

		candidate *= 2;
		idx++;
	}

	cout << answer;
}