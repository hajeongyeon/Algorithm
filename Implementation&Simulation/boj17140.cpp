#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

int r, c, k;
int arr[101][101];

void Solve()
{
	int x = 3, y = 3;

	int cnt[101] = { 0, };

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < 101; ++i)
	{
		// arr[r][c]�� ����ִ� ���� k��
		if (arr[r][c] == k)
		{
			cout << i << endl;
			return;
		}

		// R����
		if (x >= y)
		{
			for (int i = 1; i <= x; ++i)	// ��
			{
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= y; ++j)	// ��
				{
					if (arr[i][j] > 0)
					{
						cnt[arr[i][j]]++;
						arr[i][j] = 0;
					}
				}

				for (int j = 1; j < 101; ++j)
				{
					if (cnt[j] > 0) pq.push(make_pair(cnt[j], j));
				}

				int len = pq.size() * 2;
				y = max(y, len);

				for (int j = 1; j <= len; j += 2)
				{
					arr[i][j] = pq.top().second;
					arr[i][j + 1] = pq.top().first;
					pq.pop();
				}
			}
		}
		// C����
		else
		{
			for (int i = 1; i <= y; ++i)	// ��
			{
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= x; ++j)	// ��
				{
					if (arr[j][i] > 0)
					{
						cnt[arr[j][i]]++;
						arr[j][i] = 0;
					}
				}

				for (int j = 1; j < 101; ++j)
				{
					if (cnt[j] > 0) pq.push(make_pair(cnt[j], j));
				}

				int len = pq.size() * 2;
				x = max(x, len);

				for (int j = 1; j <= len; j += 2)
				{
					arr[j][i] = pq.top().second;
					arr[j + 1][i] = pq.top().first;
					pq.pop();
				}
			}
		}
	}

	// �� �Ǵ� ���� 100�� �Ѿ��
	cout << "-1" << endl;
}

void Input()
{
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}