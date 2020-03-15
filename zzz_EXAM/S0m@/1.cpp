#include <iostream>
#include <string>
using namespace std;

int num[8] = { 0, 0, 1, 7, 4, 5, 9, 8 };

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string answer = "";

	if (n == 2) cout << "2";
	else if (n == 3) cout << "7";
	else if (n == 7) cout << "51";
	else
	{
		for (int i = 2; i <= 7; ++i)
		{
			int mok = n / i;
			int na = n % i;

			if (mok == 0 || na == 1) continue;

			for (int j = 0; j < mok; ++j)
				answer += (num[i] + '0');

			if(na != 0) answer += (num[na] + '0');

			break;
		}
	}
	 
	cout << answer;
}