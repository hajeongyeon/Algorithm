#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, maxi = -1000000000, mini = 1000000000, num[100];
vector<int> oper;

void Solve()
{
	if (n == 2)
	{
		if (oper[0] == 1) maxi = mini = num[0] + num[1];
		else if (oper[0] == 2) maxi = mini = num[0] - num[1];
		else if (oper[0] == 3) maxi = mini = num[0] * num[1];
		else if (oper[0] == 4) maxi = mini = num[0] / num[1];
	}
	else
	{
		do 
		{
			int tmp = num[0];

			for (int i = 0; i < n - 1; ++i)
			{
				if (oper[i] == 1) tmp += num[i + 1];
				else if (oper[i] == 2) tmp -= num[i + 1];
				else if (oper[i] == 3) tmp *= num[i + 1];
				else if (oper[i] == 4) tmp /= num[i + 1];
			}

			maxi = max(maxi, tmp);
			mini = min(mini, tmp);
		} while (next_permutation(oper.begin(), oper.end()));
	}

	cout << maxi << "\n" << mini;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int idx = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> num[i];
	for (int i = 0; i < 4; ++i)
	{
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; ++j) oper.push_back(i + 1);
	}

	Solve();
}