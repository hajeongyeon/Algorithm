#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
char word[15];

void DFS(int mo, int ja, int cnt, int idx, string str)
{
	if (cnt >= l)
	{
		if (mo >= 1 && ja >= 2) cout << str << "\n";
		return;
	}
	if (idx >= c) return;

	if (word[idx] == 'a' || word[idx] == 'e' || word[idx] == 'i' || word[idx] == 'o' || word[idx] == 'u')
		DFS(mo + 1, ja, cnt + 1, idx + 1, str + word[idx]);
	else
		DFS(mo, ja + 1, cnt + 1, idx + 1, str + word[idx]);

	DFS(mo, ja, cnt, idx + 1, str);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> word[i];

	sort(word, word + c);

	DFS(0, 0, 0, 0, "");
}