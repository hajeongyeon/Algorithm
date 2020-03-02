/*
	���� 17135 ĳ�� ���潺
	20/03/02 09:10~10:15
	����(DFS), �ùķ��̼�
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, d, board[15][15], tmpboard[15][15], answer = -1;
bool archer[15];
vector<pair<int, int>> enemy;

void Defense()
{
	vector<int> arcpos;
	for (int i = 0; i < m; ++i)
		if (archer[i]) arcpos.push_back(i);

	memcpy(tmpboard, board, sizeof(tmpboard));
	vector<pair<int, int>> tmpenemy = enemy;

	int cnt = 0;
	while (!tmpenemy.empty())
	{
		vector<int> target;

		for (int i = 0; i < arcpos.size(); ++i)
		{
			int x = arcpos[i];
			int idx = 0;
			int enemyx = tmpenemy[0].second;
			int dist = abs(n - tmpenemy[0].first) + abs(x - tmpenemy[0].second);

			// �� ����� ���� ã�� ����
			for (int j = 1; j < tmpenemy.size(); ++j)
			{
				int tmpdist = abs(n - tmpenemy[j].first) + abs(x - tmpenemy[j].second);

				if (dist > tmpdist)
				{
					idx = j;
					enemyx = tmpenemy[j].second;
					dist = tmpdist;
				}
				// ���� ����� ���� �����̸� ���� ���ʿ� �ִ� ���� ����
				else if (dist == tmpdist && enemyx > tmpenemy[j].second)
				{
					idx = j;
					enemyx = tmpenemy[j].second;
				}
			}

			if (dist <= d) target.push_back(idx);
		}

		// �ߺ� ����
		target.erase(unique(target.begin(), target.end()), target.end());
		sort(target.begin(), target.end());

		// �� ����
		int tmpcnt = 0;
		for (int i = 0; i < target.size(); ++i)
		{
			tmpenemy.erase(tmpenemy.begin() + (target[i] - tmpcnt++));
			cnt++;
		}

		if (tmpenemy.empty()) break;

		// ��ĭ �Ʒ���
		vector<pair<int, int>> cpyenemy;
		for (int i = 0; i < tmpenemy.size(); ++i)
			if (tmpenemy[i].first < n - 1)
				cpyenemy.push_back({ tmpenemy[i].first + 1, tmpenemy[i].second });

		tmpenemy = cpyenemy;
	}

	answer = max(answer, cnt);
}

void Comb(int cnt, int idx)
{
	if (cnt == 3)
	{
		Defense();
		return;
	}

	for (int i = idx; i < m; ++i)
	{
		if (archer[i]) continue;
		archer[i] = true;
		Comb(cnt + 1, i);
		archer[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j]) enemy.push_back({ i, j });
		}
	}

	Comb(0, 0);

	cout << answer;
}