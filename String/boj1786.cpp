#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> answer;

vector<int> getPI()
{
	int m = P.size();
	int j = 0;

	vector<int> pi(m, 0);

	for (int i = 1; i < m; ++i)
	{
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}

	return pi;
}

void kmp()
{
	int n = T.size();
	int m = P.size();
	int j = 0;

	vector<int> pi = getPI();

	for (int i = 0; i < n; ++i)
	{
		while (j > 0 && T[i] != P[j])
		{
			j = pi[j - 1];
		}

		if (T[i] == P[j])
		{
			if (j == m - 1)
			{
				answer.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}
}

void Solve()
{
	kmp();

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] + 1 << "\n";
}

void Input()
{
	getline(cin, T);
	getline(cin, P);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}