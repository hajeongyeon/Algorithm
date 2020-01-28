#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> vec;
long long dp[2001][2001];

long long ioi(int, int);
long long joi(int, int);

int Plus(int x)
{
	return (x + 1) % n;
}

int Minus(int x)
{
	return (x + n - 1) % n;
}

long long ioi(int left, int right)
{
	if (Plus(right) == left) return 0;
	if (vec[Minus(left)] > vec[Plus(right)]) return joi(Minus(left), right);
	return joi(left, Plus(right));
}

long long joi(int left, int right)
{
	long long& ret = dp[left][right];

	if (ret) return ret;
	if (Plus(right) == left) return ret = 0;

	long long t1 = vec[Minus(left)] + ioi(Minus(left), right);
	long long t2 = vec[Plus(right)] + ioi(left, Plus(right));

	return ret = max(t1, t2);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		vec.push_back(a);
	}

	long long answer = 0;
	for (int i = 0; i < n; ++i)
		answer = max(answer, vec[i] + ioi(i, i));

	cout << answer;
}