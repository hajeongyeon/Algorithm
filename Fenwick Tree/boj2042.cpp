#include <iostream>
#include <vector>
using namespace std;

long long Sum(vector<long long> &tree, int idx)
{
	long long answer = 0;

	while (idx > 0)
	{
		answer += tree[idx];
		idx -= (idx & -idx);
	}

	return answer;
}

void Update(vector<long long> &tree, int idx, long long diff)
{
	while (idx < tree.size())
	{
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<long long> arr(N + 1);
	vector<long long> tree(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		Update(tree, i, arr[i]);
	}

	for (int i = 0; i < M + K; ++i)
	{
		int a; cin >> a;

		if (a == 1)
		{
			int b; 
			long long c;
			cin >> b >> c;

			long long diff = c - arr[b];
			arr[b] = c;
			Update(tree, b, diff);
		}
		else
		{
			int b; 
			long long c;
			cin >> b >> c;

			cout << Sum(tree, c) - Sum(tree, b - 1) << "\n";
		}
	}
}