#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001

int n, m, k, cost[MAX], group[MAX];
bool visited[MAX];

int Find(int x)
{
	if (x == group[x]) return x;
	return group[x] = Find(group[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	if (cost[a] < cost[b]) group[b] = a;
	else group[a] = b;
}

void Input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> cost[i];

	for (int i = 0; i <= n; ++i) group[i] = i;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		Union(a, b);
	}
}

void Solve()
{
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (Find(0) != Find(i))
		{
			answer += cost[Find(i)];
			Union(0, i);
		}
	}

	if (answer <= k) cout << answer;
	else cout << "Oh no";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}