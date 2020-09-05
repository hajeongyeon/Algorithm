// 2020.09.05 21:40~22:46
// 백준 10800 컬러볼
// 구현(nlogn), 정렬

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 200001;

struct Ball {
	int num, color, size;
};

int n, allsum, colorsum[MAX], sum[MAX];
Ball ball[MAX];

bool compare(const Ball& a, const Ball& b) { return a.size < b.size; }

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		ball[i].num = i;
		cin >> ball[i].color >> ball[i].size;
	}
}

void Solve()
{
	sort(ball, ball + n, compare);

	for (int i = 0, j = 0; i < n; ++i)
	{
		for (; ball[i].size > ball[j].size; ++j)
		{
			allsum += ball[j].size;
			colorsum[ball[j].color] += ball[j].size;
		}

		sum[ball[i].num] = allsum - colorsum[ball[i].color];
	}

	for (int i = 0; i < n; ++i)
		cout << sum[i] << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
