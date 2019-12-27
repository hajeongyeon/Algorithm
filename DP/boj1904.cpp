#include <iostream>
using namespace std;

int arr[1000001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= N; ++i) arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;

	cout << arr[N];
} 