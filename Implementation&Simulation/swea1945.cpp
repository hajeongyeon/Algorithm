#include <iostream>
using namespace std;

int main(void)
{
	int t;		// 테스트 케이스 개수
	cin >> t;

	int primefactor[5] = { 2,3,5,7,11 };

	for (int i = 1; i <= t; ++i)
	{
		int n;		// 숫자
		cin >> n;

		int savepf[5] = { 0, };		// 숫자 저장

		for (int j = 0; j < 5; ++j)
		{
			while (n % primefactor[j] == 0)
			{
				n /= primefactor[j];
				savepf[j]++;
			}
		}

		cout << "#" << i << " ";
		for (int j = 0; j < 5; ++j)
		{
			cout << savepf[j] << " ";
		}
		cout << endl;
	}
}