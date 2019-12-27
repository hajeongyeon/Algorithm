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
		// 플레이어가 죽지 않았으면 유죄 점수가 제일 높은 사람 찾기
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
	// 은진이가 죽었거나 은진이 혼자 살았을 때
	if (die[eunjin] || alive == 1)
	{
		// 은진이가 낮에 죽었으면 nightCnt - 1
		if (alive % 2 == 0) nightCnt--;
		if (answer < nightCnt) answer = nightCnt;
		return;
	}

	// 밤
	if (alive % 2 == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			// i번째 플레이어가 죽지 않았고, 은진이가 아니면
			if (!die[i] && i != eunjin)
			{
				int tmp[17];
				for (int j = 0; j < N; ++j) 
					tmp[j] = score[j];

				die[i] = true;

				// 유죄 점수 갱신
				for (int j = 0; j < N; ++j)
					score[j] += change[i][j];

				Kill(alive - 1, nightCnt);

				die[i] = false;

				for (int j = 0; j < N; ++j)
					score[j] = tmp[j];
			}
		}
	}
	// 낮
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

	// 밤 시작 -> nightCnt 1
	if (N % 2 == 0) Kill(N, 1);
	// 낮 시작 -> nightCnt 0
	else Kill(N, 0);

	cout << answer;
}