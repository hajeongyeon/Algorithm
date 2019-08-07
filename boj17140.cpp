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

	// priority_queue<자료형, 구현체, 비교연산자>
	// priority_queue에 pair를 넣으면 first에 의해 정렬됨
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < MAX; ++i)
	{
		// A[r][c]에 들어있는 값이 k면
		if (A[r][c] == k)
		{
			cout << i << endl;
			return;
		}

		if (x >= y)		// R연산
		{
			for (int i = 1; i <= x; ++i)	// 행
			{
				// 초기화
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= y; ++j)	// 열
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
		else			// C연산
		{
			for (int i = 1; i <= y; ++i)		// 열
			{
				// 초기화
				memset(cnt, 0, sizeof(cnt));

				for (int j = 1; j <= x; ++j)	// 행
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

	// 행 또는 열이 100을 넘어가면
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