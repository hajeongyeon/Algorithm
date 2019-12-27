#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int num;
int store[105][2];

void Solve()
{
	bool flag = false;
	bool visited[105] = { 0, };

	queue<pair<int, int>> q;
	// ������ ����̳� �� ��ǥ
	q.push({ store[0][0], store[0][1] });

	// BFS
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// �佺Ƽ���� ������ �� �ִٸ�
		if (x == store[num + 1][0] && y == store[num + 1][1])
		{
			flag = true;
			break;
		}

		// ����̳� ���� �����ϰ� ��� ��ġ�� Ž��
		for (int i = 1; i <= num + 1; ++i)
		{
			// �̹� �湮������ ����
			if (visited[i]) continue;

			// �Ÿ��� 1000 �ȿ� ������ ���� queue�� push
			if (abs(x - store[i][0]) + abs(y - store[i][1]) <= 1000)
			{
				q.push({ store[i][0], store[i][1] });
				visited[i] = true;
			}
		}
	}

	if (flag) cout << "happy\n";
	else cout << "sad\n";
}

void Input()
{
	memset(store, 0, sizeof(store));

	cin >> num;

	for (int i = 0; i <= num + 1; ++i) 
		cin >> store[i][0] >> store[i][1];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		Input();
		Solve();
	}
}