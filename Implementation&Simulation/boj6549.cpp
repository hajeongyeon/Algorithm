#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

/*
	** 입력은 10억인데 long long int로 선언한 이유
	43, 44번째 줄에서 height와 width를 곱할 때 int * int 하면 int형이기 때문에 overflow가 발생
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