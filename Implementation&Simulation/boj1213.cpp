#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int alpha[30] = { 0, };
	for (int i = 0; i < s.length(); ++i) alpha[s[i] - 'A']++;

	vector<pair<char, int>> v;
	vector<char> mid;
	bool flag = false;

	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] % 2 && flag)
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
		else if (alpha[i] % 2 && !flag)
		{
			v.push_back({ i + 'A', alpha[i] - 1 });
			mid.push_back(i + 'A');
			flag = true;
		}
		else
		{
			v.push_back({ i + 'A' , alpha[i] });
		}
	}

	string answer;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < (v[i].second / 2); ++j)
		{
			answer += v[i].first;
		}
	}

	for (int i = 0; i < answer.size(); ++i) cout << answer[i];
	if (mid.size()) cout << mid[0];
	for (int i = answer.size() - 1; i >= 0; --i) cout << answer[i];
	cout << "\n";
}