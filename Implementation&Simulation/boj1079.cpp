#include <iostream>
using namespace std;

int N;
int score[17];
int change[17][17];
int eunjin;

bool die[17];

int answer = 0;

int FindDeath()
{
	int idx = -1;
	int highScore = -1e9;

	for (int i = 0; i < N; ++i)
	{
		// �÷��̾ ���� �ʾ����� ���� ������ ���� ���� ��� ã��
		if (!die[i])
		{
			if (highScore < score[i])
			{
				idx = i;
				highScore = score[i];
			}
		}
	}

	return idx;
}

void Kill(int alive, int nightCnt)
{
	// �����̰� �׾��ų� ������ ȥ�� ����� ��
	if (die[eunjin] || alive == 1)
	{
		// �����̰� ���� �׾����� nightCnt - 1
		if (alive % 2 == 0) nightCnt--;
		if (answer < nightCnt) answer = nightCnt;
		return;
	}

	// ��
	if (alive % 2 == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			// i��° �÷��̾ ���� �ʾҰ�, �����̰� �ƴϸ�
			if (!die[i] && i != eunjin)
			{
				int tmp[17];
				for (int j = 0; j < N; ++j) 
					tmp[j] = score[j];

				die[i] = true;

				// ���� ���� ����
				for (int j = 0; j < N; ++j)
					score[j] += change[i][j];

				Kill(alive - 1, nightCnt);

				die[i] = false;

				for (int j = 0; j < N; ++j)
					score[j] = tmp[j];
			}
		}
	}
	// ��
	else
	{
		int Death = FindDeath();

		die[Death] = true;
		Kill(alive - 1, nightCnt + 1);
		die[Death] = false;
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; ++i) cin >> score[i];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> change[i][j];
		}
	}

	cin >> eunjin;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();

	// �� ���� -> nightCnt 1
	if (N % 2 == 0) Kill(N, 1);
	// �� ���� -> nightCnt 0
	else Kill(N, 0);

	cout << answer;
}