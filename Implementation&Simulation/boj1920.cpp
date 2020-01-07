// set »ç¿ë

#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	set<int> num;

	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		num.insert(a);
	}

	int m; cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a; cin >> a;
		if (num.find(a) != num.end()) cout << "1\n";
		else cout << "0\n";
	}
}