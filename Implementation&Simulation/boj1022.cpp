#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

int r1, r2, c1, c2;

long element(int a, int b)
{
	if (a == b)
	{
		if (a < 0)
			return (abs(a) * 2) * (abs(a) * 2) + 1;
		else if (a == 0)
			return 1;
		else
			return (a * 2 + 1) * (a * 2 + 1);
	}
	else
	{
		if (b < 0 && b < a && a < b * -1) // 왼쪽
			return (abs(b) * 2) * (abs(b) * 2) + 1 + abs(b - a);
		else if (a > 0 && b < a)	// 아래
			return (a * 2 + 1) * (a * 2 + 1) - abs(a - b);
		else if (a < 0 && a < b && b <= abs(a))	// 위
			return (abs(a) * 2) * (abs(a) * 2) + 1 - abs(b - a);
		else if (b > 0 && a < b)	// 오른쪽
			return (abs(b - 1) * 2 + 1) * (abs(b - 1) * 2 + 1) + abs(b - a);
	}
}

int main(void)
{ 
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;

	long maxlen = max(max(element(r1, c1), element(r2, c2)), max(element(r1, c2), element(r2, c1)));
	int len = to_string(maxlen).size();

	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
		{
			cout << setw(len) << element(i, j) << " ";
		}
		cout << "\n";
	}
}