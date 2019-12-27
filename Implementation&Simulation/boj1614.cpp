#include <iostream>
using namespace std;

int main(void)
{
	long num, cnt;
	cin >> num >> cnt;

	long answer = num - 1;

	if (cnt > 0)
	{
		if (num % 4 == 1) answer += 8 * cnt;
		else if (num == 2)
		{
			if (cnt % 2 == 0)
				answer += ((6 * (cnt / 2)) + (2 * (cnt / 2)));
			else
				answer += ((6 * (cnt / 2 + 1)) + (2 * (cnt / 2)));
		}
		else if (num == 3)
			answer += 4 * cnt;
		else if (num == 4)
		{
			if (cnt % 2 == 0)
				answer += ((2 * (cnt / 2)) + (6 * (cnt / 2)));
			else
				answer += ((2 * (cnt / 2 + 1)) + (6 * (cnt / 2)));
		}
	}

	cout << answer;
}