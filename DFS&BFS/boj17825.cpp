// Âü°í : https://yomyom0824.tistory.com/44

#include <iostream>
#include <algorithm>
using namespace std;

int dice[10], board[33][2], score[33], curr[4], answer;
bool check[33];

void Setting()
{
	// board setting
	for (int i = 0; i <= 24; ++i)
		board[i][0] = i + 1;

	for (int i = 22; i <= 24; ++i)
		board[i][0] = i + 1;

	board[29][0] = 30;
	board[30][0] = 25;

	for (int i = 28; i >= 26; --i)
		board[i][0] = i - 1;

	board[25][0] = 31;
	board[31][0] = 32;
	board[32][0] = 20;

	board[21][0] = 21;

	board[5][1] = 22;
	board[10][1] = 29;
	board[15][1] = 28;

	// score setting
	for (int i = 0; i <= 20; ++i)
		score[i] = i * 2;

	for (int i = 0; i < 3; ++i)
	{
		score[22 + i] = 13 + (i * 3);
		score[26 + i] = 26 + i;
	}

	score[25] = 25;

	score[29] = 22;
	score[30] = 24;

	score[31] = 30;
	score[32] = 35;
}

void DFS(int num, int total)
{
	if (num == 10)
	{
		answer = max(answer, total);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int pos = curr[i];
		int tmp = pos;
		int cnt = dice[num];

		if (pos == 5 || pos == 10 || pos == 15)
		{
			cnt--;
			pos = board[pos][1];
		}

		while (cnt--)
			pos = board[pos][0];

		if (pos != 21 && check[pos]) continue;

		curr[i] = pos;
		check[tmp] = false;
		check[pos] = true;

		DFS(num + 1, total + score[pos]);

		check[pos] = false;
		check[tmp] = true;
		curr[i] = tmp;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; ++i)
		cin >> dice[i];

	Setting();

	DFS(0, 0);

	cout << answer;
}