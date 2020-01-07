#include <iostream>
using namespace std;

bool arr[15];
bool arrL[29];
bool arrR[29];

int N;
int answer;

void DFS(int y)
{
	// 종료 조건
	if (y >= N)
	{
		answer++;
		return;
	}

	// 재귀
	for (int i = 0; i < N; ++i)
	{
		if (arr[i]) continue;
		if (arrL[y + i]) continue;
		if (arrR[N - 1 + y - i]) continue;

		arr[i] = arrL[y + i] = arrR[N - 1 + y - i] = true;
		DFS(y + 1);
		arr[i] = arrL[y + i] = arrR[N - 1 + y - i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	DFS(0);

	cout << answer;

}