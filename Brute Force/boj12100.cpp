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
		// 0이 아닌 숫자 저장 벡터
		vector<int> num;

		for (int j = 0; j < N; ++j)
		{
			// 위/아래면 board[j][i], 왼쪽/오른쪽이면 board[i][j]가 0이 아닐 때
			// num에 숫자를 저장
			if ((dir < 2 ? board[j][i] : board[i][j]) != 0)
				num.push_back(dir < 2 ? board[j][i] : board[i][j]);
		}	

		// 아래, 오른쪽 방향이면 거꾸로 저장
		if (dir == 1 || dir == 3)
			reverse(num.begin(), num.end());

		// 새로운 숫자 저장할 벡터
		vector<int> newnum;

		for (int j = 0; j < num.size(); ++j)
		{
			// num.size()-1번째 숫자가 아니고, 연속된 숫자가 같으면
			// 2배를 저장해주고 다음다음번째 수로 넘김
			if (j < num.size() - 1 && num[j] == num[j + 1])
			{
				newnum.push_back(num[j] * 2);
				j++;
			}
			// 아니면 원래 숫자 저장
			else
				newnum.push_back(num[j]);
		}

		// 남은 길이만큼 0으로 저장
		for (int j = newnum.size(); j < N; ++j)
			newnum.push_back(0);

		// 아래, 오른쪽이면 거꾸로 저장
		if (dir == 1 || dir == 3)
			reverse(newnum.begin(), newnum.end());

		// board에 바뀐 숫자 저장
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

		// 원래대로 되돌림
		memcpy(board, tmp, sizeof(board));
	}
}

void Solve()
{
	// 중복순열
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