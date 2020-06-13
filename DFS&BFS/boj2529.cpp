// 2020.06.13 23:30 ~ 2020.06.14 12:21
// 백준 2529 부등호
// DFS

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k;
char ineq[10];
bool visited[10];
vector<string> candi;

void Recursion(int idx, int cnt, string str)
{
	if (cnt == k)
	{
		candi.push_back(str);
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (!visited[i])
			{
				if (ineq[cnt] == '<')
				{
					if (idx >= i) continue;
				}
				else
					if (idx <= i) continue;

				visited[i] = true;
				Recursion(i, cnt + 1, str + to_string(i));
			}
		}
	}

	visited[idx] = false;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 0; i < k; ++i) cin >> ineq[i];

	for (int i = 0; i < 10; ++i)
	{
		visited[i] = true;
		Recursion(i, 0, to_string(i) + "");
	}

	cout << candi[candi.size() - 1] << "\n" << candi[0];
}
