#include <iostream>
using namespace std;

void preorder(int lv, int curr, int n)
{
	if (lv == 1)
	{
		cout << curr << " ";
		return;
	}

	int start = (1 << n) - (1 << (n - lv + 1));
	int lvmax = (1 << (n - lv));

	cout << lvmax - curr + 1 + start << " ";
	preorder(lv - 1, curr, n);
	preorder(lv - 1, curr + (1 << (n - lv)), n);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	preorder(n, 1, n);
}