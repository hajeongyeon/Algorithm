#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

/*
	** �Է��� 10���ε� long long int�� ������ ����
	43, 44��° �ٿ��� height�� width�� ���� �� int * int �ϸ� int���̱� ������ overflow�� �߻�
	https://www.acmicpc.net/board/view/20742
*/
long long int height[100001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(1)
	{
		int N;
		stack<int> s;
		long long int answer = 0;

		cin >> N;
		if (N == 0) break;

		memset(height, 0, sizeof(height));
		for (int i = 0; i < N; ++i) cin >> height[i];

		for (int i = 0; i <= N; ++i)
		{
			while (!s.empty() && height[s.top()] >= height[i])
			{
				int idx = s.top();
				s.pop();

				int width = 0;

				if (s.empty())
					width = i;
				else
					width = i - s.top() - 1;

				if (answer < height[idx] * width)
					answer = height[idx] * width;
			}

			s.push(i);
		}

		cout << answer << "\n";
	}
}