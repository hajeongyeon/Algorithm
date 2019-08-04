#include <iostream>
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		int n;
		cin >> n;

		int answer = 1;
		for (int j = 2; j <= n; ++j)
		{
			if (j % 2 == 0)
			{
				answer -= j;
			}
			else
			{
				answer += j;
			}
		}

		cout << "#" << n << " " << answer << endl;
	}
}