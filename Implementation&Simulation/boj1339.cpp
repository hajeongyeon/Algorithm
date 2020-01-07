#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	int alphabet[26] = { 0, };
	vector<int> vec;
	int cnt = 9;
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str; cin >> str;

		for (int j = 0; j < str.length(); ++j)
			alphabet[str[j] - 'A'] += (int)pow(10, str.length() - j - 1);
	}

	for (int i = 0; i < 26; ++i)
		if (alphabet[i]) vec.push_back(alphabet[i]);

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); ++i)
		answer += vec[i] * (cnt--);

	cout << answer;
}