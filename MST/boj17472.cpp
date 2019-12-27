// 2019.10.01 17:51~19:46
// ���� 17472 �ٸ� �����2
// DFS, MST(Kruskal)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ٸ� ����ü
// ��߼� ��ȣ, ������ ��ȣ, �Ÿ�
struct Bridge {
	int u, v, dist;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M;
int Map[10][10];

vector<pair<int, int>> island[7];		// �� ��ǥ ���� ����
vector<pair<int, int>> islandEdge[7];	// �� �����ڸ� ��ǥ ���� ����
bool visited[10][10];

vector<Bridge> br;							// �ٸ� ����
int group[7] = { 0, 1, 2, 3, 4, 5, 6 };		// Union-Find -- Make-Set

bool isRange(int x, int y)
{
	if (x < 0 || y < 0 || y >= M || x >= N) return false;
	return true;
}

void FindIsland(int x, int y, int num)
{
	bool isBr = false;	// ���� �����ڸ��� ã�� ���� boolean�� ����
	Map[x][y] = num;	// ���� ��ȣ�� �°� �ٲ۴�.

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// ������ �ƴϰ�, �̹� �湮�ߴٸ� continue
		if (!isRange(nx, ny)) continue;
		if (visited[nx][ny]) continue;
		// �ֺ��� ���̸� �����ڸ��̹Ƿ� true. �׸��� ���� �ƴϴϱ� continue
		if (Map[nx][ny] != 1)
		{
			isBr = true;
			continue;
		}

		visited[nx][ny] = true;
		island[num].push_back({ nx, ny });
		FindIsland(nx, ny, num);
	}

	// �����ڸ��� push_back
	if (isBr) islandEdge[num].push_back({ x, y });
}

void MakeBridge(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		int len = 0;	// ����
		int dest = 0;	// ������ ���� ��ȣ

		// ������ ����� �ʰ�, �ٴٸ� ��� �����
		while (isRange(nx, ny) && Map[nx][ny] == 0)
		{
			nx += dx[i];
			ny += dy[i];
			len++;
		}

		// ������ ����� �ʾҴµ� while���� ���� ������ ���� �����Ŵϱ� dest�� �� ��ȣ�� �־��ش�.
		if (isRange(nx, ny)) dest = Map[nx][ny];
		// �ٸ��� ���̰� 2 �̻��̰� dest�� 0�� �ƴϸ� �ٸ� ���Ϳ� ��߼�, ������ ��ȣ�� �ٸ��� ���̸� �־��ش�.
		if (len >= 2 && dest) br.push_back({ Map[x][y], dest, len });
	}
}

int FindSet(int x)
{
	if (x == group[x]) return x;
	return group[x] = FindSet(group[x]);
}

void UnionSet(int a, int b)
{
	a = FindSet(a);
	b = FindSet(b);

	// �θ� ������ return
	if (a == b) return;

	// a, b�� �� ������ ��ħ
	group[b] = a;
}

int compare_dist(const Bridge& a, const Bridge& b)
{
	return a.dist < b.dist;
}

int Kruskal()
{
	int answer = 0;

	// �ٸ��� ���̸� ������������ ����
	sort(br.begin(), br.end(), compare_dist);

	for (int i = 0; i < br.size(); ++i)
	{
		// �θ� ��尡 ������ continue
		if (FindSet(br[i].u) == FindSet(br[i].v)) continue;

		answer += br[i].dist;
		UnionSet(br[i].u, br[i].v);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> Map[i][j];

	// 1. DFS�� ����� ���� ã�´�.
	int num = 0;	// �� ��ȣ
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!visited[i][j] && Map[i][j] == 1)
			{
				num++;
				FindIsland(i, j, num);
			}
		}
	}

	// 2. �ٸ��� ������ش�.
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 0; j < islandEdge[i].size(); ++j)
		{
			MakeBridge(islandEdge[i][j].first, islandEdge[i][j].second);
		}
	}

	// 3. MST�� �ּ� �Ÿ��� ã�´�. (ũ�罺Į ���)
	int answer = Kruskal();

	// 4. ��� ���� �� ���Ҵ��� Ȯ���Ѵ�.
	int uf_first = FindSet(1);
	for (int i = 2; i <= num; ++i) if (uf_first != FindSet(i)) answer = 0;

	if (answer == 0) cout << "-1";
	else cout << answer;
}