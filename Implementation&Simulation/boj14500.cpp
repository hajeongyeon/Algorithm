// ���õ� �ϵ��ڵ��Դϴ�.. ���� �Ф�

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];
int answer = 0;

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
}

bool isRange(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}

void Imino(int x, int y)
{
	int tmp = 0;

	// ��
	for (int i = 0; i < 4; ++i)
	{
		if (!isRange(x, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y + i];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	answer = max(answer, tmp);
}

void Omino(int x, int y)
{
	int tmp = 0;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (!isRange(x + i, y + j))
			{
				tmp = -1;
				break;
			}
			tmp += board[x + i][y + j];
		}
	}
	answer = max(answer, tmp);
}

void Zmino(int x, int y)
{
	int tmp = 0;

	// 
	for (int i = 0; i < 2; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		for (int i = 1; i < 3; ++i)
		{
			if (!isRange(x + i, y - 1))
			{
				tmp = -1;
				break;
			}
			tmp += board[x + i][y - 1];
		}
	}
	answer = max(answer, tmp);

	//
	tmp = 0;
	for (int i = 0; i < 2; ++i)
	{
		if (!isRange(x, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y + i];
	}
	if (tmp != -1)
	{
		for (int i = 1; i < 3; ++i)
		{
			if (!isRange(x + 1, y + i))
			{
				tmp = -1;
				break;
			}
			tmp += board[x + 1][y + i];
		}
	}
	answer = max(answer, tmp);
}

void Smino(int x, int y)
{
	int tmp = 0;

	// 
	for (int i = 0; i < 2; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		for (int i = 1; i < 3; ++i)
		{
			if (!isRange(x + i, y + 1))
			{
				tmp = -1;
				break;
			}
			tmp += board[x + i][y + 1];
		}
	}
	answer = max(answer, tmp);

	//
	tmp = 0;
	for (int i = 0; i < 2; ++i)
	{
		if (!isRange(x, y - i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y - i];
	}
	if (tmp != -1)
	{
		for (int i = 1; i < 3; ++i)
		{
			if (!isRange(x + 1, y - i))
			{
				tmp = -1;
				break;
			}
			tmp += board[x + 1][y - i];
		}
	}
	answer = max(answer, tmp);
}

void Jmino(int x, int y)
{
	int tmp = 0;

	// ��
	tmp += board[x][y];
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + 1, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + 1][y + i];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		if (!isRange(x, y + 1)) tmp = -1;
		else tmp += board[x][y + 1];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y + i];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 1, y + 2)) tmp = -1;
		else tmp += board[x + 1][y + 2];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 2, y - 1)) tmp = -1;
		else tmp += board[x + 2][y - 1];
	}
	answer = max(answer, tmp);
}

void Lmino(int x, int y)
{
	int tmp = 0;
	
	// ��
	tmp += board[x][y];
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + 1, y - i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + 1][y - i];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 2, y + 1)) tmp = -1;
		else tmp += board[x + 2][y + 1];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y + i];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 1, y)) tmp = -1;
		else tmp += board[x + 1][y];
	}
	answer = max(answer, tmp);

	// ��
	tmp = 0;
	tmp += board[x][y];
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + i, y + 1))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y + 1];
	}
	answer = max(answer, tmp);
}

void Tmino(int x, int y)
{
	int tmp = 0;

	// ��
	tmp += board[x][y];
	for (int i = -1; i < 2; ++i)
	{
		if (!isRange(x + 1, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + 1][y + i];
	}
	answer = max(answer, tmp);

	// ������
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x + i, y))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 1, y + 1)) tmp = -1;
		else tmp += board[x + 1][y + 1];
	}
	answer = max(answer, tmp);

	// �Ʒ�
	tmp = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (!isRange(x, y + i))
		{
			tmp = -1;
			break;
		}
		tmp += board[x][y + i];
	}
	if (tmp != -1)
	{
		if (!isRange(x + 1, y + 1)) tmp = -1;
		else tmp += board[x + 1][y + 1];
	}
	answer = max(answer, tmp);

	// ����
	tmp = 0;
	tmp += board[x][y];
	for (int i = -1; i < 2; ++i)
	{
		if (!isRange(x + i, y + 1))
		{
			tmp = -1;
			break;
		}
		tmp += board[x + i][y + 1];
	}
	answer = max(answer, tmp);
}

void Solve()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Imino(i, j);
			Omino(i, j);
			Zmino(i, j);
			Smino(i, j);
			Jmino(i, j);
			Lmino(i, j);
			Tmino(i, j);
		}
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}