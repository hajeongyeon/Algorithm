#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int seq[100001];

void Solve()
{
	int ans = 1e9, s = 0, e = 0, sum = seq[0];

	while (e < N && s <= e)
	{
		if (sum > S)
		{
			ans = min(ans, (e - s + 1));
			sum -= seq[s++];
		}
		else if (sum == S)
		{
			ans = min(ans, (e - s + 1));
			sum += seq[++e];
		}
		else
			sum += seq[++e];
	}

	if (ans == 1e9) cout << "0";
	else cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	Solve();
}