// 총감독은 오직 1명, 부감독은 여러 명 가능

#include <iostream>
using namespace std;

int main(void)
{
	int n;	// 시험장 수
	cin >> n;
	
	int *ppl = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> ppl[i];
	}

	int super, asst;	// 총감독관이 한 방에서 감시할 수 있는 응시자 수, 부감독관이 한 방에서 감시할 수 있는 응시자 수
	cin >> super >> asst;

	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		ppl[i] -= super;
		answer++;

		if (ppl[i] > 0)
		{
			if (ppl[i] % asst == 0)
			{
				answer += (ppl[i] / asst);
			}
			else
			{
				answer += (ppl[i] / asst + 1);
			}
		}
	}

	cout << answer;

	delete[] ppl;
}