#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct BC_Info {
	int x, y, c, p;
};

int M, A;				// 이동 시간, BC의 개수
int moveInfo[2][101];	// 사용자의 이동 정보
BC_Info bc[8];			// BC 정보

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };

void Input()
{
	cin >> M >> A;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < M; ++j)
			cin >> moveInfo[i][j];

	for (int i = 0; i < A; ++i)
		cin >> bc[i].x >> bc[i].y >> bc[i].c >> bc[i].p;
}

int Charge(pair<int, int> ppl[])
{
	int maxCharge = 0;
	bool checkA[8] = { 0, }, checkB[8] = { 0, };

	for (int i = 0; i < A; ++i)
	{
		// 무선 충전기 범위 안이라면
		if (abs(ppl[0].first - bc[i].x) + abs(ppl[0].second - bc[i].y) <= bc[i].c) checkA[i] = true;
		if (abs(ppl[1].first - bc[i].x) + abs(ppl[1].second - bc[i].y) <= bc[i].c) checkB[i] = true;
	}

	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < A; ++j)
		{
			int tmpCharge = 0;

			if (i == j)
			{
				if (checkA[i] || checkB[i]) 
					tmpCharge = bc[i].p;
			}
			else
			{
				if (checkA[i]) tmpCharge += bc[i].p;
				if (checkB[j]) tmpCharge += bc[j].p;
			}

			maxCharge = max(maxCharge, tmpCharge);
		}
	}

	return maxCharge;
}

void Solve(int tc)
{
	int MaxCharge = 0;
	pair<int, int> ppl[2] = { { 1, 1 }, {10, 10} };
	MaxCharge += Charge(ppl);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			ppl[j].first += dx[moveInfo[j][i]];
			ppl[j].second += dy[moveInfo[j][i]];
		}

		MaxCharge += Charge(ppl);
	}

	cout << "#" << tc << " " << MaxCharge << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		Input();
		Solve(tc);

		memset(moveInfo, 0, sizeof(moveInfo));
		memset(bc, 0, sizeof(bc));
	}
}