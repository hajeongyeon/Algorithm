#include <iostream>
#include <vector>
using namespace std;

vector<int> employee[100001];
int nag[100001];

void Solve(int curr)
{
	for (int i = 0; i < employee[curr].size(); ++i)
	{
		nag[employee[curr][i]] += nag[curr];
		Solve(employee[curr][i]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int super; cin >> super;
	for (int i = 2; i <= n; ++i)
	{
		cin >> super;
		employee[super].push_back(i);
	}

	for (int i = 0; i < m; ++i)
	{
		int num, w;
		cin >> num >> w;

		nag[num] += w;
	}

	Solve(1);

	for (int i = 1; i <= n; ++i)
		cout << nag[i] << " ";
}