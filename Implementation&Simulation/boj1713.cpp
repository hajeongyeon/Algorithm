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
		// 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 게시된 지 가장 오래된 사진을 삭제한다.
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

		// 4. 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
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

		// 비어있는 사진틀이 있음
		if (candid.size() < N)
		{
			candid.push_back({num, 1, i});
			continue;
		}

		// 3. 비어있는 사진틀이 없는 경우
		priority_queue<Candidate> pq;
		for (int j = 0; j < candid.size(); ++j) pq.push(candid[j]);

		for (int j = 0; j < candid.size(); ++j)
		{
			if (candid[j].num == pq.top().num)
			{
				// 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 
				// 그 자리에 새롭게 추천받은 학생의 사진을 게시한다.
				candid[j].num = num;
				candid[j].vote = 1;
				candid[j].times = i;

				// 5. 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
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