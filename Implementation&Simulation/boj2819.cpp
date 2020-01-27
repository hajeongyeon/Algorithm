#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
vector<int> x_invest, y_invest;
string command;

void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		x_invest.push_back(x);
		y_invest.push_back(y);
	}

	cin >> command;
}

void Solve()
{
	// lower_bound를 쓰기 위해 x, y 각각 오름차순으로 정렬함
	sort(x_invest.begin(), x_invest.end());
	sort(y_invest.begin(), y_invest.end());

	// 상근 로봇 좌표
	int s_x = 0, s_y = 0;

	// 초기 조사점의 거리
	long long dist = 0;
	for (int i = 0; i < n; ++i)
		dist += (abs(x_invest[i]) + abs(y_invest[i]));

	// k -> k + 1 (S, I의 경우)일 때, k + 1 이상이면 1 감소, 미만이면 1 증가
	// k + 1 -> k (J, Z의 경우)일 때, k + 1 이상이면 1 증가, 미만이면 1 감소
	for (int i = 0; i < m; ++i)
	{
		switch (command[i])
		{
		case 'S':
		{
			s_y++;
			auto lb = lower_bound(y_invest.begin(), y_invest.end(), s_y) - y_invest.begin();
			dist += (-1 * (n - lb) + lb);
			cout << dist << "\n";
			break;
		}

		case 'I':
		{
			s_x++;
			auto lb = lower_bound(x_invest.begin(), x_invest.end(), s_x) - x_invest.begin();
			dist += (-1 * (n - lb) + lb);
			cout << dist << "\n";
			break;
		}

		case 'J':
		{
			auto lb = lower_bound(y_invest.begin(), y_invest.end(), s_y) - y_invest.begin();
			dist += ((n - lb) - lb);
			cout << dist << "\n";
			s_y--;
			break;
		}

		case 'Z':
		{
			auto lb = lower_bound(x_invest.begin(), x_invest.end(), s_x) - x_invest.begin();
			dist += ((n - lb) - lb);
			cout << dist << "\n";
			s_x--;
			break;
		}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}