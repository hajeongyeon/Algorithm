#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> rowPF[5];
vector<vector<pair<int, int>>> colPF[5];
vector<pair<int, int>> row[6];
vector<pair<int, int>> col[6];

void MakeRowPF()
{
	// 141
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			vector<pair<int, int>> tmprow;

			tmprow.push_back({ 0, i });
			tmprow.push_back({ 2, j });
			for (int k = 0; k < 4; ++k)
				tmprow.push_back({ 1, k });

			rowPF[0].push_back(tmprow);
		}
	}

	// 231
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			vector<pair<int, int>> tmprow;

			tmprow.push_back({ 0, i * 2 });
			tmprow.push_back({ 0, i * 2 + 1 });

			if (i == 0)
			{
				tmprow.push_back({ 2, j + 1 });
				for (int k = 0; k < 3; ++k)
					tmprow.push_back({ 1, k + 1 });
			}
			else
			{
				tmprow.push_back({ 2, j });
				for (int k = 0; k < 3; ++k)
					tmprow.push_back({ 1, k });
			}

			rowPF[1].push_back(tmprow);
		}
	}

	// 132
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			vector<pair<int, int>> tmprow;

			tmprow.push_back({ 2, i * 2 });
			tmprow.push_back({ 2, i * 2 + 1 });

			if (i == 0)
			{
				tmprow.push_back({ 0, j + 1 });
				for (int k = 0; k < 3; ++k)
					tmprow.push_back({ 1, k + 1 });
			}
			else
			{
				tmprow.push_back({ 0, j });
				for (int k = 0; k < 3; ++k)
					tmprow.push_back({ 1, k });
			}

			rowPF[2].push_back(tmprow);
		}
	}

	// 222
	for (int i = 0; i < 2; ++i)
	{
		vector<pair<int, int>> tmprow;

		if (i == 0)
		{
			for (int j = 0; j < 3; ++j)
			{
				tmprow.push_back({ j, j });
				tmprow.push_back({ j, j + 1 });
			}
		}
		else
		{
			tmprow.push_back({ 0, 2 });
			tmprow.push_back({ 0, 3 });
			tmprow.push_back({ 1, 1 });
			tmprow.push_back({ 1, 2 });
			tmprow.push_back({ 2, 0 });
			tmprow.push_back({ 2, 1 });
		}

		rowPF[3].push_back(tmprow);
	}

	// 33
	for (int i = 0; i < 2; ++i)
	{
		vector<pair<int, int>> tmprow;

		if (i == 0)
		{
			tmprow.push_back({ 0, 0 });
			tmprow.push_back({ 0, 1 });
			tmprow.push_back({ 0, 2 });
			tmprow.push_back({ 1, 2 });
			tmprow.push_back({ 1, 3 });
			tmprow.push_back({ 1, 4 });
		}
		else
		{
			tmprow.push_back({ 1, 0 });
			tmprow.push_back({ 1, 1 });
			tmprow.push_back({ 1, 2 });
			tmprow.push_back({ 0, 2 });
			tmprow.push_back({ 0, 3 });
			tmprow.push_back({ 0, 4 });
		}

		rowPF[4].push_back(tmprow);
	}
}

void MakeColPF()
{
	for (int n = 0; n < 5; ++n)
	{
		for (int i = 0; i < rowPF[n].size(); ++i)
		{
			vector<pair<int, int>> tmpcol;

			for (int j = 0; j < rowPF[n][i].size(); ++j)
			{
				int x = rowPF[n][i][j].first;
				int y = rowPF[n][i][j].second;

				tmpcol.push_back({ y, x });
			}

			colPF[n].push_back(tmpcol);
		}
	}
}

bool CheckOverlapRow(int num)
{
	vector<pair<int, int>> tmprow;
	int x = 1e9, y = 1e9;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < row[i].size(); ++j)
		{
			x = min(x, row[i][j].first);
			y = min(y, row[i][j].second);

			tmprow.push_back({ row[i][j].first, row[i][j].second });
		}
	}

	for (int i = 0; i < rowPF[num].size(); ++i)
	{
		int cnt = 0;
		bool flag = false;

		for (int j = 0; j < rowPF[num][i].size(); ++j)
		{
			int nx = x + rowPF[num][i][j].first;
			int ny = y + rowPF[num][i][j].second;

			for (int k = 0; k < tmprow.size(); ++k)
			{
				if (nx == tmprow[k].first && ny == tmprow[k].second)
				{
					cnt++;
					break;
				}
			}

			if (cnt == 6)
			{
				flag = true;
				break;
			}
		}

		if (flag) return true;
	}

	return false;
}

bool CheckOverlapCol(int num)
{
	vector<pair<int, int>> tmpcol;
	int x = 1e9, y = 1e9;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < col[i].size(); ++j)
		{
			x = min(x, col[i][j].first);
			y = min(y, col[i][j].second);

			tmpcol.push_back({ col[i][j].first, col[i][j].second });
		}
	}

	for (int i = 0; i < colPF[num].size(); ++i)
	{
		int cnt = 0;
		bool flag = false;

		for (int j = 0; j < colPF[num][i].size(); ++j)
		{
			int nx = x + colPF[num][i][j].first;
			int ny = y + colPF[num][i][j].second;

			for (int k = 0; k < tmpcol.size(); ++k)
			{
				if (nx == tmpcol[k].first && ny == tmpcol[k].second)
				{
					cnt++;
					break;
				}
			}

			if (cnt == 6)
			{
				flag = true;
				break;
			}
		}

		if (flag) return true;
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	MakeRowPF();
	MakeColPF();

	for (int tc = 0; tc < 3; ++tc)
	{
		for (int i = 0; i < 6; ++i)
		{
			row[i].clear();
			col[i].clear();
		}

		int arr[6][6] = { 0, };

		for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 6; ++j)
				cin >> arr[i][j];

		int rowCnt = 0;
		bool check = false;
		for (int i = 0; i < 6; ++i)
		{
			check = false;
			for (int j = 0; j < 6; ++j)
			{
				if (arr[i][j] == 1)
				{
					check = true;
					row[rowCnt].push_back({ i, j });
				}
			}
			if (check) rowCnt++;
		}

		int colCnt = 0;
		for (int i = 0; i < 6; ++i)
		{
			check = false;
			for (int j = 0; j < 6; ++j)
			{
				if (arr[j][i] == 1)
				{
					check = true;
					col[colCnt].push_back({ j, i });
				}
			}
			if (check) colCnt++;
		}

		bool answer = false;

		// 가로
		if (rowCnt == 3)
		{
			if (row[0].size() == 1)
			{
				if (row[1].size() == 4 && row[2].size() == 1)
					answer = CheckOverlapRow(0);
				else if(row[1].size() == 3 && row[2].size() == 2)
					answer = CheckOverlapRow(2);
			}
			else if (row[0].size() == 2)
			{
				if (row[1].size() == 3 && row[2].size() == 1)
					answer = CheckOverlapRow(1);
				else if (row[1].size() == 2 && row[2].size() == 2)
					answer = CheckOverlapRow(3);
			}
		}
		else if (rowCnt == 2)
		{
			answer = CheckOverlapRow(4);
		}

		// 세로
		if (colCnt == 3)
		{
			if (col[0].size() == 1)
			{
				if (col[1].size() == 4 && col[2].size() == 1)
					answer = CheckOverlapCol(0);
				else if (col[1].size() == 3 && col[2].size() == 2)
					answer = CheckOverlapCol(2);
			}
			else if (col[0].size() == 2)
			{
				if (col[1].size() == 3 && col[2].size() == 1)
					answer = CheckOverlapCol(1);
				else if (col[1].size() == 2 && col[2].size() == 2)
					answer = CheckOverlapCol(3);
			}
		}
		else if (colCnt == 2)
		{
			answer = CheckOverlapCol(4);
		}

		if (answer) cout << "yes\n";
		else cout << "no\n";
	}
}