// https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019

#include <iostream>
using namespace std;

int digit = 1;
int answer[10] = { 0, };

void calculate(int num)
{
	for (int i = num; i > 0; i /= 10) 
		answer[i % 10] += digit;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int end;
	int start = 1;
	
	cin >> end;

	while (start <= end)
	{
		while (start % 10 != 0 && start <= end)
		{
			calculate(start);
			start++;
		}

		if (start > end) break;

		while (end % 10 != 9 && start <= end)
		{
			calculate(end);
			end--;
		}

		start /= 10; end /= 10;

		for (int i = 0; i < 10; ++i)
			answer[i] += (end - start + 1) * digit;

		digit *= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << answer[i] << " ";
}