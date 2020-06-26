// 2020.06.26 23:12~
// 백준 1826 연료 채우기
// 

#include <iostream>
using namespace std;

int n, l, p;
pair<int, int> arr[10000];

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i) 
		cin >> arr[i].first >> arr[i].second;

	cin >> l >> p;
}

void Solve()
{
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
