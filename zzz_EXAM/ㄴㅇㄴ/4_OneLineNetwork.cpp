#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

int N;
int computer[200005];
long long cable[200005];
vector<int> numone;

void Input()
{
	numone.clear();
	memset(computer, 0, sizeof(computer));
	memset(cable, 0, sizeof(cable));

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> computer[i];

		if (computer[i] == 1) numone.push_back(i);
	}
}

void Solve(int tc)
{
	deque<int> fivecom;

	if (numone.empty())
	{
		cout << "#" << tc << " 0 " << N << "\n";
		return;
	}

	int num = numone[0];
	int cnt = 0;
	int bundle = 0;

	int idx = 0;
	while (cnt == 0)
	{
		if (idx == N)
		{
			cout << "#" << tc << " " << "0 " << N << "\n";
			return;
		}

		while (num != 0)
		{
			num--;

			if (!computer[num] && cnt < 5)
			{
				cnt++;
				cable[numone[idx]] += cnt;
				fivecom.push_front(num);
			}
			else if (!computer[num] && cnt >= 5) bundle++;
		}

		idx++;
		if (idx < numone.size()) num = numone[idx];
		bundle++;
	}

	for (int i = idx; i < numone.size(); ++i)
	{
		int dist = numone[i] - numone[i - 1];

		if (dist > 5)
		{
			cable[numone[i]] = cable[numone[i - 1]] + 15;
			bundle++;
			cnt = 0;

			while (!fivecom.empty()) fivecom.pop_back();
			while (cnt < 5)
			{
				cnt++;
				fivecom.push_front(numone[i] - cnt);
			}

			if (dist - 6 > 0) bundle += (dist - 6);
		}
		else
		{
			if (dist == 1)
			{
				int tmp = 0;
				for (int j = 0; j < fivecom.size(); ++j)
					tmp += (numone[i] - fivecom[j]);

				cable[numone[i]] = cable[numone[i - 1]] + tmp;
			}
			else
			{
				if (cnt < 5)
				{
					for (int j = dist - 2; j >= 0; --j)
					{
						if (cnt >= 5)
						{
							fivecom.pop_front();
							cnt--;
						}

						fivecom.push_back(numone[i] - j - 1);
						cnt++;
					}
				}
				else
				{
					for (int j = dist - 2; j >= 0; --j)
					{
						fivecom.pop_front();
						cnt--;
						fivecom.push_back(numone[i] - j - 1);
						cnt++;
					}
				}

				int tmp = 0;
				for (int j = 0; j < fivecom.size(); ++j)
					tmp += (numone[i] - fivecom[j]);

				cable[numone[i]] = cable[numone[i - 1]] + tmp;
			}
		}
	}

	num = numone[numone.size() - 1];
	for (int i = num; i < N - 1; ++i) bundle++;

	cout << "#" << tc << " " << cable[num] << " " << bundle << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		Input();
		Solve(tc);
	}
}