// 2020.09.07 22:24~22:57
// 프로그래머스 크레인 인형뽑기 게임
// 구현(스택)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
	int answer = 0;

	stack<int> doll;

	for (int i = 0; i < moves.size(); ++i)
	{
		int r = moves[i] - 1;

		for (int j = 0; j < board.size(); ++j)
		{
			if (board[j][r] != 0)
			{
				if (!doll.empty() && doll.top() == board[j][r])
				{
					doll.pop();
					answer += 2;
				}
				else
				{
					doll.push(board[j][r]);
				}

				board[j][r] = 0;
				break;
			}
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<vector<int>> board{ {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1},{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1} };
	vector<int> moves;

	for (int i = 0; i < 25; ++i)
	{
		int a; cin >> a;
		moves.push_back(a);
	}

	cout << solution(board, moves);
}