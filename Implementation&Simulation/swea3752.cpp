#include <iostream>
#include <cstring>
using namespace std;

int score[100];
int result[10000];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		memset(score, 0, sizeof(score));
		memset(result, 0, sizeof(result));

		int n;
		cin >> n;

		int max = 0;
		result[0] = 1;

		for (int i = 0; i < n; ++i)
		{
			cin >> score[i];
			max += score[i];

			for (int j = max; j >= 0; --j)
				if (result[j] > 0) result[j + score[i]]++;
		}

		int answer = 0;
		for (int i = 0; i < 10000; ++i)
			if (result[i] > 0) answer++;

		cout << "#" << tc << " " << answer << "\n";
	}
}