// 2020.08.18 19:41~20:15
// 백준 1946 신입사원
// 그리디

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int Solve(vector<pair<int, int>> v)
{
	// 서류 성적 순위 오름차순 정렬
	sort(v.begin(), v.end(), compare);

	int ans = 1, iv = v[0].second;

	for (int i = 1; i < n; ++i)
	{
		// 통과하려면 면접 성적 순위가 좋아야함
		if (v[i].second < iv) ans++;
		iv = min(iv, v[i].second);
	}

	return ans;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc; cin >> tc;

	for (int t = 0; t < tc; ++t)
	{
		cin >> n;

		vector<pair<int, int>> vec;
	
		for (int i = 0; i < n; ++i)
		{
			int a, b; cin >> a >> b;

			vec.push_back({ a, b });
		}

		cout << Solve(vec) << "\n";
	}
}
