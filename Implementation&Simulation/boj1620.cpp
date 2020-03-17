#include <iostream>
#include <string>
#include <map>
using namespace std;

string pok2[100001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	string str;
	map<string, int> pok;
	char c;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
	
		pok2[i] = str;
		pok.insert(pair<string, int>(str, i));
	}

	for (int j = 0; j < m; ++j)
	{
		cin.ignore(20, '\n');
		c = cin.peek();

		if (c >= '0' && c <= '9')
		{
			int num; cin >> num;
			cout << pok2[num] << "\n";
		}
		else
		{
			cin >> str;
			cout << pok[str] << "\n";
		}
	}
}