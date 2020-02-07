// https://survivalking.tistory.com/37 참고했습니다
// 세그먼트 트리 너무 어려워요 ㅠㅠㅠ

#include <iostream>
#include <vector>
using namespace std;

#define MAX_TEMP 65536
typedef long long ll;

int n, k;
ll answer, segment[250001];

ll Update(int idx, int val, int node, int s, int e)
{
	if (idx < s || idx > e) return segment[node];
	if (s == e) return segment[node] += val;

	int mid = (s + e) / 2;
	return segment[node] = Update(idx, val, node * 2, s, mid) + Update(idx, val, node * 2 + 1, mid + 1, e);
}

ll Find(ll val, int node, int s, int e)
{
	if (s == e) return s;

	int mid = (s + e) / 2;

	if (segment[node * 2] >= val) return Find(val, node * 2, s, mid);
	return Find(val - segment[node * 2], node * 2 + 1, mid + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	vector<ll> temp(n);
	for (int i = 0; i < n; ++i)
		cin >> temp[i];

	for (int i = 0; i < k - 1; ++i)
		Update(temp[i], 1, 1, 0, MAX_TEMP - 1);

	for (int i = k - 1; i < n; ++i)
	{
		Update(temp[i], 1, 1, 0, MAX_TEMP - 1);
		answer += Find((k + 1) / 2, 1, 0, MAX_TEMP - 1);
		Update(temp[i - k + 1], -1, 1, 0, MAX_TEMP - 1);
	}

	cout << answer;
}