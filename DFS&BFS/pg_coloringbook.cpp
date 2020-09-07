// 2020.09.07 23:00~23:17
// 프로그래머스 카카오프렌즈 컬러링북
// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	bool visited[100][100] = { 0, };

	for(int i = 0; i < picture.size(); ++i)
	{
		for (int j = 0; j < picture[i].size(); ++j)
		{
			if (visited[i][j] || !picture[i][j]) continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			int color = picture[i][j];
			int tmpsize = 1;
			number_of_area++;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
					if (picture[nx][ny] != color) continue;

					tmpsize++;
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}

			max_size_of_one_area = max(max_size_of_one_area, tmpsize);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m, n;
	vector<vector<int>> picture{ {1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} };

	cin >> m >> n;

	vector<int> answer = solution(m, n, picture);

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
}