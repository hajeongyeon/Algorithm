// 2020.06.19 23:00~23:42
// 백준 3079 입국심사
// 이분탐색

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long arr[100000];

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}

void Solve()
{
	sort(arr, arr + n);

	long long left = 0, right = m * arr[n - 1];
	long long answer = m * arr[n - 1];

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;

		// 몇 명이 지났는지 체크
		for (int i = 0; i < n; ++i)
			cnt += mid / arr[i];

		// 인원 처리가 가능하다면
		if (cnt >= m)
		{
			// 최소 시간 저장 후 인원 처리 상한 값 재설정
			answer = min(answer, mid);
			right = mid - 1;
		}
		// 불가능하면(시간 부족) 하한 값 재설정
		else
			left = mid + 1;
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
