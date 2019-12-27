#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX(a, b) a > b ? a : b

// 의존, 시간
vector<pair<int, int>> v[10001];
int infection[10001];
int start;

void Dijkstra(int n)
{
	int cnt = 1;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while(!pq.empty())
	{
		int currNode = pq.top().second;
		int t = -1 * pq.top().first;
		pq.pop();

		if (infection[currNode] < t)
		{
			cnt--;
			continue;
		}

		for (int i = 0; i < v[currNode].size(); ++i)
		{
			int newV = infection[currNode] + v[currNode][i].second;
			int pastV = infection[v[currNode][i].first];

			if (newV < pastV)
			{
				infection[v[currNode][i].first] = newV;
				pq.push({ -1 * newV, v[currNode][i].first });
				cnt++;
			}
		}
	}

	int Time = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (infection[i] != 1e9) 
			Time = MAX(Time, infection[i]);
	}

	cout << cnt << " " << Time << "\n";
}

void Solve()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		int n, d, c;
		cin >> n >> d >> c;

		start = c;

		for (int i = 1; i <= n; ++i)
		{
			v[i].clear();
			infection[i] = 1e9;
		}
		infection[start] = 0;

		for (int i = 0; i < d; ++i)
		{
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a, s });
		}

		Dijkstra(n);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Solve();
}