#include <iostream>
using namespace std;

int ccw(int p1[], int p2[], int p3[])
{
	int tmp = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1];
	tmp = tmp - p1[1] * p2[0] - p2[1] * p3[0] - p3[1] * p1[0];

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int p1[2], p2[2], p3[2];
	cin >> p1[0] >> p1[1] >> p2[0] >> p2[1] >> p3[0] >> p3[1];

	cout << ccw(p1, p2, p3);
}