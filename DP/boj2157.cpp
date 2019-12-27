#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int airway[301][301];
int save[301][301];

int FindMax(int curr, int visited)
{
	// M번 방문했는데 N번 도시에 도달하지 못했을 때
	if (visited == M && curr != N) return -1e9;
	// N번 도시에 도달
	if (curr == N) return 0;

	int& ret = save[curr][visited];
	if (ret) return ret;

	for (int i = curr + 1; i <= N; ++i)
	{
		if (airway[curr][i])
			ret = max(ret, airway[curr][i] + FindMax(i, visited + 1));
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		airway[a][b] = max(airway[a][b], c);
	}

	cout << FindMax(1, 1);
}