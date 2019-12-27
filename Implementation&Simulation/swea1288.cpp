#include <iostream>
using namespace std;

int main(void)
{
	int t;			// 테스트 수
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		int n;		// N
		cin >> n;

		int arr[10] = { 0, };		// 숫자를 봤는지 체크
		int answer = 0;				// 답
		int sv = n;					// save

		for (int j = 0; ; ++j)
		{
			int tmp = sv;			// N 임시 저장
			while (sv != 0)
			{
				arr[sv % 10] = 1;
				sv /= 10;
			}

			int cnt = 0;		// 10번 세는지 확인
			for (int k = 0; k < 10; ++k)
			{
				if (arr[k] == 1) cnt++;
			}

			if (cnt == 10)
			{
				answer = tmp;
				break;
			}

			sv = n * j;
		}

		cout << "#" << i << " " << answer << endl;
	}
}