// 2020.06.26 23:12 ~ 2020.06.27 01:38
// 백준 1826 연료 채우기
// 그리디&힙

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, l, p;
pair<int, int> arr[10001];
priority_queue<int> pq;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i) 
		cin >> arr[i].first >> arr[i].second;

	cin >> l >> p;
}

void Solve()
{
	int idx = 0, ans = 0;

	sort(arr, arr + n);

	while (p < l)
	{
		// 갈 수 있는 거리보다 가까운 주유소를 모두 저장
		// 가장 큰 연료량을 가진 주유소 순으로 저장
		while (arr[idx].first <= p)
		{
			if (idx == n) break;
			pq.push(arr[idx].second);
			idx++;
		}

		// 더 이상 갈 수 없음
		if (pq.empty()) break;

		ans++;
		p += pq.top();
		pq.pop();
	}

	if (p < l) cout << "-1";
	else cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
