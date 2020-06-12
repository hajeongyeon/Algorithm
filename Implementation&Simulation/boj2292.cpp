#include <iostream>
using namespace std;

int main(void)
{
	long long n;
	cin >> n;

	int room = 1;
	int num = 1;
	int add = 6;

	while (1)
	{
		if (n <= num)
		{
			break;
		}

		room++;
		num += add;
		add += 6;
	}

	cout << room;
}