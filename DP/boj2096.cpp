#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	int dpMax[3] = { 0, }, dpMin[3] = { 0, };
	int tmpMax[3] = { 0, }, tmpMin[3] = { 0, };
	int MAX = -1, MIN = 1e9;

	cin >> N;
	cin >> dpMax[0] >> dpMax[1] >> dpMax[2];

	dpMin[0] = dpMax[0];
	dpMin[1] = dpMax[1];
	dpMin[2] = dpMax[2];

	for (int i = 1; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				tmpMax[0] = max(dpMax[0], dpMax[1]) + a;
				tmpMin[0] = min(dpMin[0], dpMin[1]) + a;
			}
			else if (j == 1)
			{
				tmpMax[1] = max(max(dpMax[0], dpMax[1]), dpMax[2]) + b;
				tmpMin[1] = min(min(dpMin[0], dpMin[1]), dpMin[2]) + b;
			}
			else
			{
				tmpMax[2] = max(dpMax[1], dpMax[2]) + c;
				tmpMin[2] = min(dpMin[1], dpMin[2]) + c;
			}
		}

		for (int j = 0; j < 3; ++j)
		{
			dpMax[j] = tmpMax[j];
			dpMin[j] = tmpMin[j];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		MAX = max(MAX, dpMax[i]);
		MIN = min(MIN, dpMin[i]);
	}

	cout << MAX << " " << MIN;
}