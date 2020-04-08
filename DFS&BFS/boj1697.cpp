#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	queue<pair<int, int>> q;

	cin >> n >> k;

	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty())
	{
		int num = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (num == k) 
		{
			cout << sec;
			break;
		}

		if (num - 1 >= 0 && !visited[num - 1])
		{
			q.push({ num - 1, sec + 1 });
			visited[num - 1] = true;
		}
		if (num + 1 <= 100000 && !visited[num + 1])
		{
			q.push({ num + 1, sec + 1 });
			visited[num + 1] = true;
		}
		if (num * 2 <= 100000 && !visited[num * 2])
		{
			q.push({ num * 2, sec + 1 });
			visited[num * 2] = true;
		}
	}
}