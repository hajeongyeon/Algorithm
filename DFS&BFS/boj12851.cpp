#include <iostream>
#include <queue>
using namespace std;

int visited[100001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, sec = 0, cnt = 0;
	queue<int> q;

	cin >> n >> k;

	q.push(n);

	while (!cnt)
	{
		int s = q.size();
		while (s--)
		{
			int x = q.front(); q.pop();
			if (x == k) cnt++;
			
			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx > 100000) continue;
				if (visited[nx] && visited[nx] != visited[x] + 1) continue;

				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
		}

		sec++;
	}

	cout << sec - 1 << "\n" << cnt;
}