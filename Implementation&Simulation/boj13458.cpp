// �Ѱ����� ���� 1��, �ΰ����� ���� �� ����

#include <iostream>
using namespace std;

int main(void)
{
	int n;	// ������ ��
	cin >> n;
	
	int *ppl = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> ppl[i];
	}

	int super, asst;	// �Ѱ������� �� �濡�� ������ �� �ִ� ������ ��, �ΰ������� �� �濡�� ������ �� �ִ� ������ ��
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