#include <iostream>
using namespace std;

int main(void)
{
	int n;		// 수 개수
	cin >> n;

	int answer = 0;		// 답

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		bool isPrime = false;

		for (int j = 2; j < x; ++j)
		{
			if (x % j == 0)
			{
				isPrime = true;
			}
		}

		if (!isPrime && x != 1) answer++;
	}

	cout << answer;
}