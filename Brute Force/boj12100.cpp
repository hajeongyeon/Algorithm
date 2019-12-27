#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int board[21][21];
int tmp[21][21];

int result = 0;

void Play(int dir)
{
	for (int i = 0; i < N; ++i)
	{
		// 0�� �ƴ� ���� ���� ����
		vector<int> num;

		for (int j = 0; j < N; ++j)
		{
			// ��/�Ʒ��� board[j][i], ����/�������̸� board[i][j]�� 0�� �ƴ� ��
			// num�� ���ڸ� ����
			if ((dir < 2 ? board[j][i] : board[i][j]) != 0)
				num.push_back(dir < 2 ? board[j][i] : board[i][j]);
		}	

		// �Ʒ�, ������ �����̸� �Ųٷ� ����
		if (dir == 1 || dir == 3)
			reverse(num.begin(), num.end());

		// ���ο� ���� ������ ����
		vector<int> newnum;

		for (int j = 0; j < num.size(); ++j)
		{
			// num.size()-1��° ���ڰ� �ƴϰ�, ���ӵ� ���ڰ� ������
			// 2�踦 �������ְ� ����������° ���� �ѱ�
			if (j < num.size() - 1 && num[j] == num[j + 1])
			{
				newnum.push_back(num[j] * 2);
				j++;
			}
			// �ƴϸ� ���� ���� ����
			else
				newnum.push_back(num[j]);
		}

		// ���� ���̸�ŭ 0���� ����
		for (int j = newnum.size(); j < N; ++j)
			newnum.push_back(0);

		// �Ʒ�, �������̸� �Ųٷ� ����
		if (dir == 1 || dir == 3)
			reverse(newnum.begin(), newnum.end());

		// board�� �ٲ� ���� ����
		for (int j = 0; j < N; ++j)
			(dir < 2 ? board[j][i] : board[i][j]) = newnum[j];
	}
}

void Multi_Permutation(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				result = max(result, board[i][j]);
			}
		}

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int tmp[21][21];
		memcpy(tmp, board, sizeof(tmp));

		Play(i);
		Multi_Permutation(cnt + 1);

		// ������� �ǵ���
		memcpy(board, tmp, sizeof(board));
	}
}

void Solve()
{
	// �ߺ�����
	Multi_Permutation(0);

	cout << result << endl;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}