#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> bus[6001];
long long dist[501];

bool bellmanford()
{
	bool cycle = false;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[j] == 1e9) continue;

			for (int k = 0; k < bus[j].size(); ++k)
			{
				int next = bus[j][k].first;
				int next_w = bus[j][k].second;

				if (dist[next] > dist[j] + next_w)
				{
					dist[next] = dist[j] + next_w;

					if (i == n)
						cycle = true;
				}
			}
		}
	}

	if (cycle) return true;
	else return false;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bus[a].push_back({ b, c });
	}

	for (int i = 1; i <= n; ++i)
		dist[i] = 1e9;

	dist[1] = 0;

	if (bellmanford())
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if (dist[i] == 1e9)
				cout << "-1\n";
			else
				cout << dist[i] << "\n";
		}
	}
}
