#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Candidate 
{
	int num, vote, times;

	Candidate(int num, int vote, int times) : num(num), vote(vote), times(times) {};

	bool operator < (const Candidate& c) const
	{
		// ������� ��õ ���� Ƚ���� ���� ���� �л��� �� �� �̻��� ��쿡�� �Խõ� �� ���� ������ ������ �����Ѵ�.
		if (vote == c.vote) return times > c.times;
		else return vote > c.vote;
	}
};

int N, recom_num;

void Solve()
{
	int recommand[101] = { 0, };
	vector<Candidate> candid;

	for (int i = 0; i < recom_num; ++i)
	{
		int num; cin >> num;

		// 4. ���� ������ �Խõ� �л��� �ٸ� �л��� ��õ�� ���� ��쿡�� ��õ���� Ƚ���� ������Ų��.
		if (recommand[num])
		{
			for (int i = 0; i < candid.size(); ++i)
			{
				if (candid[i].num == num)
				{
					candid[i].vote++;
					break;
				}
			}

			continue;
		}

		recommand[num]++;

		// ����ִ� ����Ʋ�� ����
		if (candid.size() < N)
		{
			candid.push_back({num, 1, i});
			continue;
		}

		// 3. ����ִ� ����Ʋ�� ���� ���
		priority_queue<Candidate> pq;
		for (int j = 0; j < candid.size(); ++j) pq.push(candid[j]);

		for (int j = 0; j < candid.size(); ++j)
		{
			if (candid[j].num == pq.top().num)
			{
				// ������� ��õ ���� Ƚ���� ���� ���� �л��� ������ �����ϰ�, 
				// �� �ڸ��� ���Ӱ� ��õ���� �л��� ������ �Խ��Ѵ�.
				candid[j].num = num;
				candid[j].vote = 1;
				candid[j].times = i;

				// 5. ����Ʋ�� �Խõ� ������ �����Ǵ� ��쿡�� �ش� �л��� ��õ���� Ƚ���� 0���� �ٲ��.
				recommand[pq.top().num] = 0;

				break;
			}
		}
	}

	vector<int> answer;
	for (int i = 0; i < candid.size(); ++i) answer.push_back(candid[i].num);

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> recom_num;

	Solve();
}