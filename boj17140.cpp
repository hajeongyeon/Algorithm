#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int MAX = 101;

void solve(int A[][MAX], int r, int c, int k)
{
	int x = 3, y = 3;

	int cnt[MAX] = { 0, };

	// priority_queue<�ڷ���, ����ü, �񱳿�����>
	// priority_queue�� pair�� ������ first�� ���� ���ĵ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < MAX; ++i)
	{
		// A[r][c]�� ����ִ� ���� k��
		if (A[r][c] == k)
		{
			cout << i << endl;
			return;
		}

		if (x >= y)		// R����
		{
			for (int i = 1; i <= x; ++i)	// ��
			{
				// �ʱ�ȭ
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= y; ++j)	// ��
				{
					if (A[i][j] > 0)
					{
						cnt[A[i][j]]++;
						A[i][j] = 0;
					}
				}

				for (int j = 1; j < MAX; ++j)
				{
					if (cnt[j] > 0) pq.push(make_pair(cnt[j], j));
				}

				int len = pq.size() * 2;
				y = max(y, len);

				for (int j = 1; j <= len; j += 2)
				{
					A[i][j] = pq.top().second;
					A[i][j + 1] = pq.top().first;
					pq.pop();
				}
			}
		}
		else			// C����
		{
			for (int i = 1; i <= y; ++i)		// ��
			{
				// �ʱ�ȭ
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= x; ++j)	// ��
				{
					if (A[j][i] > 0)
					{
						cnt[A[j][i]]++;
						A[j][i] = 0;
					}
				}

				for (int j = 1; j < MAX; ++j)
				{
					if (cnt[j] > 0) pq.push(make_pair(cnt[j], j));
				}

				int len = pq.size() * 2;
				x = max(x, len);

				for (int j = 1; j <= len; j += 2)
				{
					A[j][i] = pq.top().second;
					A[j + 1][i] = pq.top().first;
					pq.pop();
				}
			}
		}
	}

	// �� �Ǵ� ���� 100�� �Ѿ��
	cout << "-1" << endl;
}

int main(void)
{
	int r, c, k;
	cin >> r >> c >> k;

	int A[MAX][MAX] = { 0, };

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> A[i][j];
		}
	}

	solve(A, r, c, k);
}