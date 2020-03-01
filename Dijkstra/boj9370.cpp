#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

// S -> G -> H -> T (S->G, G->H, H->T)
// S -> H -> G -> T (S->H, H->G, G->T)

// G -> H랑 H -> G는 같음
// 1) S -> T, S -> G는 시작점을 S로 하는 다익스트라
// 2) H -> T는 시작점을 H로 하는 다익스트라
// 3) G -> T는 시작점을 G로 하는 다익스트라

// 교차로, 도로, 목적지, 예술가 출발지, g, h
int n, m, t, s, g, h, s_dist[2001], g_dist[2001], h_dist[2001], gh_dist;
vector<pair<int, int>> road[2001];

void Dijkstra(int start, int arr[])
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	arr[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first * -1;
		int curr = pq.top().second;
		pq.pop();

		for (auto i : road[curr])
		{
			int n_dist = i.second;
			int nxt = i.first;

			if (arr[nxt] > dist + n_dist)
			{
				arr[nxt] = dist + n_dist;
				pq.push({ arr[nxt] * -1, nxt });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	
	for (int tc = 0; tc < T; ++tc)
	{
		cin >> n >> m >> t >> s >> g >> h;

		int a, b, d;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> d;

			road[a].push_back({ b, d });
			road[b].push_back({ a, d });

			if ((a == g && b == h) || (a == h && b == g)) gh_dist = d;
		}

		for (int i = 1; i <= n; ++i)
		{
			s_dist[i] = 1e9;
			g_dist[i] = 1e9;
			h_dist[i] = 1e9;
		}

		Dijkstra(s, s_dist);
		Dijkstra(g, g_dist);
		Dijkstra(h, h_dist);

		int x;
		vector<int> answer;

		for (int i = 0; i < t; ++i)
		{
			cin >> x;

			if (s_dist[g] + gh_dist + h_dist[x] == s_dist[x]) answer.push_back(x);
			else if (s_dist[h] + gh_dist + g_dist[x] == s_dist[x]) answer.push_back(x);
		}
		
		sort(answer.begin(), answer.end());

		for (auto i : answer) cout << i << " ";
		cout << "\n";

		memset(road, 0, sizeof(road));
	}
}