#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, cost;
};

int parent[10005];

// Find-Set : �θ� ��� ã��
int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

// Union-Set
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	// ����Ŭ �����ϸ� return
	if (a == b) return;

	cout << a << " " << b << endl;

	parent[b] = a;
}

int compare_cost(const Edge& a, const Edge& b)
{
	return a.cost < b.cost;
}

int Kruskal(vector<Edge>& edge)
{
	int answer = 0;

	// ������ ����ġ�� ���� �������� ����
	sort(edge.begin(), edge.end(), compare_cost);

	// ����ġ�� ���� �������� �����ϸ鼭 Ʈ�� ����
	for (int i = 0; i < edge.size(); ++i)
	{
		// ����Ŭ�� �����ϸ� continue
		if (Find(edge[i].u) == Find(edge[i].v)) continue;

		answer += edge[i].cost;
		Union(edge[i].u, edge[i].v);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<Edge> edge;

	int V, E;
	cin >> V >> E;

	// Make-Set : parent�� �ڱ� �ڽ��� �ʱ�ȭ
	for (int i = 0; i <= V; ++i) parent[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int u, v, cost;
		cin >> u >> v >> cost;

		edge.push_back({ u, v, cost });
	}

	cout << Kruskal(edge);
}