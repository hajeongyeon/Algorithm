#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[501];
int n, arr[501], indegree[501], Time[501];

void topologySort()
{
	queue<int> q;

	for (int i = 1; i <= n; ++i)
		if (!indegree[i]) q.push(i);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); ++i)
		{
			if (--indegree[vec[x][i]] == 0)
				q.push(vec[x][i]);

			int tmp = arr[x] + Time[x];
			if (tmp > Time[vec[x][i]])
				Time[vec[x][i]] = tmp;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];

		int num;
		while (cin >> num)
		{
			if (num == -1) break;

			vec[num].push_back(i);
			indegree[i]++;
		}
	}

	topologySort();

	for (int i = 1; i <= n; ++i)
		cout << arr[i] + Time[i] << "\n";
}