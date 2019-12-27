#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, cost;
};

int parent[10005];

// Find-Set : 부모 노드 찾기
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

	// 사이클 존재하면 return
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

	// 간선을 가중치에 따라 오름차순 정렬
	sort(edge.begin(), edge.end(), compare_cost);

	// 가중치가 낮은 간선부터 선택하면서 트리 증가
	for (int i = 0; i < edge.size(); ++i)
	{
		// 사이클이 존재하면 continue
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

	// Make-Set : parent를 자기 자신을 초기화
	for (int i = 0; i <= V; ++i) parent[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int u, v, cost;
		cin >> u >> v >> cost;

		edge.push_back({ u, v, cost });
	}

	cout << Kruskal(edge);
}