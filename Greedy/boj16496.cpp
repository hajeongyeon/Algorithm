#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int arr[1000];

bool cmp(const string& a, const string& b)
{
	return a + b > b + a ? true : false;
}

void Solve()
{
	string answer = "";

	vector<string> strv;

	for (int i = 0; i < N; ++i)
		strv.push_back(to_string(arr[i]));

	sort(strv.begin(), strv.end(), cmp);

	for (string str : strv) answer += str;

	if (answer[0] == '0') cout << "0";
	else cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	Solve();
}