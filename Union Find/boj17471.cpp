// 백준 17471 게리맨더링
// 조합, union-find

#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) (a < b) ? a : b

int N;
bool check[11][11];		// 연결된 구역 체크 배열
int ppl[11];			// 인구 수 저장
int group[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	// union-find를 위한 배열
int answer = 1e9;

vector<int> firstarea, secondarea;	// 2개의 구역

int Find(int a)
{
	if (a == group[a]) return a;
	return group[a] = Find(group[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	group[b] = a;
}

void FindParents()
{
	int fsize = firstarea.size();
	int ssize = secondarea.size();

	// Union
	if (firstarea.size() > 1)
	{
		for (int i = 0; i < fsize - 1; ++i)
		{
			for (int j = i + 1; j < fsize; ++j)
			{
				if (check[firstarea[i]][firstarea[j]]) Union(firstarea[i], firstarea[j]);
			}
		}
	}
	if (secondarea.size() > 1)
	{
		for (int i = 0; i < ssize - 1; ++i)
		{
			for (int j = i + 1; j < ssize; ++j)
			{
				if (check[secondarea[i]][secondarea[j]]) Union(secondarea[i], secondarea[j]);
			}
		}
	}

	// 선거구 수 구하기
	bool parents[11] = { 0, };
	int cnt = 0;
	for (int i = 1; i <= N; ++i) parents[Find(i)] = true;
	for (int i = 1; i <= N; ++i) if (parents[i]) cnt++;
	// 선거구 수가 2가 아니면 return
	if (cnt != 2) return;

	// 1선거구, 2선거구의 인구를 구해줌
	int fppl = 0, sppl = 0;
	for (int i = 0; i < fsize; ++i) fppl += ppl[firstarea[i]];
	for (int i = 0; i < ssize; ++i) sppl += ppl[secondarea[i]];

	// 최소 인구차 구하기
	answer = MIN(answer, abs(fppl - sppl));
}

// 조합 함수
void Combination(bool visited[], int s, int r)
{
	// 모든 수를 다 뽑았다면
	if (r == 0)
	{
		// 초기화
		// !!중요!! 벡터 초기화 안 해주면 쌓임 & group 초기화 안 해주면 group에 1로 들어감
		firstarea.clear();
		secondarea.clear();
		for (int i = 0; i <= N; ++i) group[i] = i;

		// 체크됐으면 firstarea에 push, 아니면 secondarea에 push
		for (int i = 1; i <= N; ++i)
		{
			if (visited[i]) firstarea.push_back(i);
			else secondarea.push_back(i);
		}

		// Union-Find
		FindParents();
	}
	// r만큼 수 뽑기
	else
	{
		for (int i = s; i <= N; ++i)
		{
			visited[i] = true;
			Combination(visited, i + 1, r - 1);
			visited[i] = false;
		}
	}
}

void Input()
{
	cin >> N;

	// 인구수 입력
	for (int i = 1; i <= N; ++i) cin >> ppl[i];

	// 인접 구역 정보 입력
	for (int i = 1; i <= N; ++i)
	{
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; ++j)
		{
			int tmp;
			cin >> tmp;

			check[i][tmp] = true;
			check[tmp][i] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 함수
	Input();

	// 조합
	// ex) 5C2 = 5C3이므로 N/2까지만 반복
	for (int i = 1; i <= N / 2; ++i)
	{
		bool visited[11] = { 0, };
		Combination(visited, 1, i);
	}

	// answer이 1e9면 두 선거구를 나눌 수 없는 것이므로 -1 출력
	if (answer == 1e9) answer = -1;
	cout << answer;
}
