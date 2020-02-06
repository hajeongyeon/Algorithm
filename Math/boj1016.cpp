#include <iostream>
using namespace std;

#define MAX 1000001

bool prime[MAX], check[MAX];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, x;
	cin >> n >> x;

	long long answer = x - n + 1;

	for (long long i = 2; i * i <= x; ++i)
	{
		long long sqr = i * i;

		if (prime[i]) continue;
		for (long long j = i; j * j <= x; j += i) prime[j] = true;
		for (long long j = ((n - 1) / sqr + 1) * sqr; j <= x; j += sqr)
		{
			if (!check[j - n])
			{
				check[j - n] = true;
				answer--;
			}
		}
	}

	cout << answer;
}