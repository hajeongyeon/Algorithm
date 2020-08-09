// 2020.08.09 17:52~18:45
// 백준 4195 친구 네트워크
// Union-Find

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int parent[200002];
int relation[200002];

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

int Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a != b)
	{
		parent[a] = b;
		relation[b] += relation[a];
		relation[a] = 1;
	}

	return relation[b];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc; cin >> tc;

	for (int t = 0; t < tc; ++t)
	{
		unordered_map<string, int> name;
		int idx = 1;

		int r; cin >> r;

		for (int i = 0; i <= r * 2; ++i)
		{
			parent[i] = i;
			relation[i] = 1;
		}
		
		for (int i = 0; i < r; ++i)
		{
			string a, b;
			cin >> a >> b;
		
			if (name.find(a) == name.end()) name.insert({ a, idx++ });
			if (name.find(b) == name.end()) name.insert({ b, idx++ });

			int anum = name.find(a)->second;
			int bnum = name.find(b)->second;

			cout << Union(anum, bnum) << "\n";
		}
	}
}
