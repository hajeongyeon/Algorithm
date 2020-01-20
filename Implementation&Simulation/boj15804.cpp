#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, arrival = 1, idx = 0;
	pair<int, int> bus[101];
	deque<pair<int, int>> station;

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
		cin >> bus[i].first >> bus[i].second;
	
	while (1)
	{
		while (!station.empty() && station.front().second <= arrival)
			station.pop_front();

		while ((station.empty() || station.back().first < n) && bus[idx].first <= arrival)
		{
			pair<int, int> tmp;

			if (station.empty())
				tmp = { 1, arrival + bus[idx].second };
			else
				tmp = { station.back().first + 1, arrival + bus[idx].second };

			if (idx == m - 1)
			{
				cout << tmp.first;
				return 0;
			}

			station.push_back(tmp);
			idx++;
		}

		arrival++;
	}
}