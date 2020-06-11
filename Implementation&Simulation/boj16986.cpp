#include <iostream>
#include <algorithm>
using namespace std;

const int JW = 1;
const int KH = 2;
const int MH = 3;

int N, K;

int board[10][10];
int action[4][21];

int WinCnt[4];
bool JiwooWin = false;

// player 2명의 번호와 지우, 경희, 민호의 라운드가 매개변수
void Play(int Player1, int Player2, int JWRound, int KHRound, int MHRound)
{
	// 지우가 이긴 횟수가 K번 이상
	if (WinCnt[JW] >= K)
	{
		JiwooWin = true;
		return;
	}
	// 경희 또는 민호가 이긴 횟수가 K번 이상
	else if (WinCnt[KH] >= K || WinCnt[MH] >= K) return;

	// 다음 플레이어
	int nextPlayer = 0;

	if ((Player1 == JW && Player2 == KH) || (Player1 == KH && Player2 == JW)) nextPlayer = MH;
	else if ((Player1 == KH && Player2 == MH) || (Player1 == MH && Player2 == KH)) nextPlayer = JW;
	else if ((Player1 == JW && Player2 == MH) || (Player1 == MH && Player2 == JW)) nextPlayer = KH;

	// 다음 플레이어가 지우이면 경희 vs 민호
	if (nextPlayer == JW)
	{
		// 경희가 이김
		if (board[action[KH][KHRound]][action[MH][MHRound]] == 2)
		{
			WinCnt[KH]++;
			Play(KH, nextPlayer, JWRound, KHRound + 1, MHRound + 1);
		}
		// 민호가 이김
		else
		{
			WinCnt[MH]++;
			Play(MH, nextPlayer, JWRound, KHRound + 1, MHRound + 1);
		}
	}
	// 다음 플레이어가 경희면 지우 vs 민호
	else if (nextPlayer == KH)
	{
		// 지우가 이김
		if (board[action[JW][JWRound]][action[MH][MHRound]] == 2)
		{
			WinCnt[JW]++;
			Play(JW, nextPlayer, JWRound + 1, KHRound, MHRound + 1);
		}
		// 민호가 이김
		else
		{
			WinCnt[MH]++;
			Play(MH, nextPlayer, JWRound + 1, KHRound, MHRound + 1);
		}
	}
	// 다음 플레이어가 민호면 지우 vs 경희
	else if (nextPlayer == MH)
	{
		// 지우가 이김
		if (board[action[JW][JWRound]][action[KH][KHRound]] == 2)
		{
			WinCnt[JW]++;
			Play(JW, nextPlayer, JWRound + 1, KHRound + 1, MHRound);
		}
		// 경희가 이김
		else
		{
			WinCnt[KH]++;
			Play(KH, nextPlayer, JWRound + 1, KHRound + 1, MHRound);
		}
	}
}

void Solve()
{
	// 지우가 낼 수 있는 손동작을 순열로 구함
	do
	{
		memset(WinCnt, 0, sizeof(WinCnt));
		Play(1, 2, 1, 1, 1);

		if (JiwooWin)
		{
			cout << "1";
			return;
		}
	} while (next_permutation(action[1] + 1, action[1] + 1 + N));

	cout << "0";
}

void Input()
{
	cin >> N >> K;

	// 상성 정보
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 경희&민호 손동작
	for (int i = 2; i < 4; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			cin >> action[i][j];
		}
	}

	// 지우 손동작 1~N까지 저장
	for (int i = 1; i <= N; ++i)
		action[1][i] = i;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}