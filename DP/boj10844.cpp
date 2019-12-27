#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int arr[101][10] = { 0, };

	for (int i = 1; i <= 9; ++i) arr[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j <= 8; ++j) arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		arr[i][9] = arr[i - 1][8];
	}

	long answer = 0;
	for (int i = 0; i <= 9; ++i) answer += arr[N][i];

	answer %= 1000000000;

	cout << answer;
}