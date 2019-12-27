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

// player 2���� ��ȣ�� ����, ����, ��ȣ�� ���尡 �Ű�����
void Play(int Player1, int Player2, int JWRound, int KHRound, int MHRound)
{
	// ���찡 �̱� Ƚ���� K�� �̻�
	if (WinCnt[JW] >= K)
	{
		JiwooWin = true;
		return;
	}
	// ���� �Ǵ� ��ȣ�� �̱� Ƚ���� K�� �̻�
	else if (WinCnt[KH] >= K || WinCnt[MH] >= K) return;

	// ���� �÷��̾�
	int nextPlayer = 0;

	if ((Player1 == JW && Player2 == KH) || (Player1 == KH && Player2 == JW)) nextPlayer = MH;
	else if ((Player1 == KH && Player2 == MH) || (Player1 == MH && Player2 == KH)) nextPlayer = JW;
	else if ((Player1 == JW && Player2 == MH) || (Player1 == MH && Player2 == JW)) nextPlayer = KH;

	// ���� �÷��̾ �����̸� ���� vs ��ȣ
	if (nextPlayer == JW)
	{
		// ���� �̱�
		if (board[action[KH][KHRound]][action[MH][MHRound]] == 2)
		{
			WinCnt[KH]++;
			Play(KH, nextPlayer, JWRound, KHRound + 1, MHRound + 1);
		}
		// ��ȣ�� �̱�
		else
		{
			WinCnt[MH]++;
			Play(MH, nextPlayer, JWRound, KHRound + 1, MHRound + 1);
		}
	}
	// ���� �÷��̾ ����� ���� vs ��ȣ
	else if (nextPlayer == KH)
	{
		// ���찡 �̱�
		if (board[action[JW][JWRound]][action[MH][MHRound]] == 2)
		{
			WinCnt[JW]++;
			Play(JW, nextPlayer, JWRound + 1, KHRound, MHRound + 1);
		}
		// ��ȣ�� �̱�
		else
		{
			WinCnt[MH]++;
			Play(MH, nextPlayer, JWRound + 1, KHRound, MHRound + 1);
		}
	}
	// ���� �÷��̾ ��ȣ�� ���� vs ����
	else if (nextPlayer == MH)
	{
		// ���찡 �̱�
		if (board[action[JW][JWRound]][action[KH][KHRound]] == 2)
		{
			WinCnt[JW]++;
			Play(JW, nextPlayer, JWRound + 1, KHRound + 1, MHRound);
		}
		// ���� �̱�
		else
		{
			WinCnt[KH]++;
			Play(KH, nextPlayer, JWRound + 1, KHRound + 1, MHRound);
		}
	}
}

void Solve()
{
	// ���찡 �� �� �ִ� �յ����� ������ ����
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

	// �� ����
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
		}
	}

	// ����&��ȣ �յ���
	for (int i = 2; i < 4; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			cin >> action[i][j];
		}
	}

	// ���� �յ��� 1~N���� ����
	for (int i = 1; i <= N; ++i)
		action[1][i] = i;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}