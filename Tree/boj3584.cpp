#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 10001;

vector<int> graph[MAX];
int depth[MAX], connect[MAX], parent[MAX][20], lv;

void Init()
{
	for (int i = 0; i < MAX; ++i)
		graph[i].clear();
	memset(depth, 0, sizeof(depth));
	memset(connect, 0, sizeof(connect));
	memset(parent, 0, sizeof(parent));
	lv = 0;
}

void getTree(int curr, int p)
{
	depth[curr] = depth[p] + 1;
	parent[curr][0] = p;

	lv = (int)floor(log2(MAX));
	for (int i = 1; i <= lv; ++i)
	{
		int tmp = parent[curr][i - 1];
		parent[curr][i] = parent[tmp][i - 1];
	}

	for (int i = 0; i < graph[curr].size(); ++i)
	{
		if (graph[curr][i] != p)
			getTree(graph[curr][i], curr);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		Init();

		int n; cin >> n;

		int a, b;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);

			connect[b] = a;
		}

		int root = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!connect[i])
			{
				root = i;
				break;
			}
		}

		depth[0] = -1;

		getTree(root, 0);

		cin >> a >> b;

		if (depth[a] > depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		for (int i = lv; i >= 0; --i)
			if (depth[a] <= depth[parent[b][i]])
				b = parent[b][i];

		int lca = a;

		if (a != b)
		{
			for (int i = lv; i >= 0; --i)
			{
				if (parent[a][i] != parent[b][i])
				{
					a = parent[a][i];
					b = parent[b][i];
				}

				lca = parent[a][i];
			}
		}

		cout << lca << "\n";
	}
}