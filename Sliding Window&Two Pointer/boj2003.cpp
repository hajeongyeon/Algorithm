#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10005];

void Solve()
{
	int ans = 0, s = 0, e = 0, sum = 0;

	while (1)
	{
		if (sum >= M)
			sum -= arr[s++];
		else if (e == N) break;
		else
			sum += arr[e++];

		if (sum == M) ans++;
	}

	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	Solve();
}