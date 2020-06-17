// 2020.06.18 02:36~03:22
// 백준 1931 회의실 배정
// 그리디

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;
vector<pair<int, int>> t;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		t.push_back({ a, b });
	}
}

// 일찍 끝나는 회의를 기준으로 잡음
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	// 끝나는 시간이 같으면 시작하는 시간이 빠른 순으로 정렬
	if (a.second == b.second)
		return (a.first < b.first);
	// 다르면 일찍 끝나는 시간 순으로 정렬
	else
		return (a.second < b.second);
}

void Solve()
{
	sort(t.begin(), t.end(), cmp);

	int min_t = t[0].second;
	answer++;

	for (int i = 1; i < n; ++i)
	{
		if (min_t <= t[i].first)
		{
			min_t = t[i].second;
			answer++;
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
