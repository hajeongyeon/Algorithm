#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct info {
	int x, y, p, q;
};

int n;
info coord[100001];

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		coord[i].x = x;
		coord[i].y = y;
		coord[i].p = 1;
		coord[i].q = 0;
	}
}

// y��ǥ, x��ǥ�� ���� ������ ����
bool compare(const info& a, const info& b)
{
	if (1LL * a.q * b.p != 1LL * a.p * b.q)
		return 1LL * a.q * b.p < 1LL * a.p * b.q;

	if (a.y != b.y) return a.y < b.y;

	return a.x < b.x;
}

long long ccw(const info& f, const info& s, const info& n)
{
	return 1LL * (f.x * s.y + s.x * n.y + n.x * f.y - s.x * f.y - n.x * s.y - f.x * n.y);
}

void Solve()
{
	// 1. �������� ��´�. (���� y��ǥ�� ���� ���� ���� ��������)
	sort(coord, coord + n, compare);

	for (int i = 1; i < n; ++i)
	{
		coord[i].p = coord[i].x - coord[0].x;
		coord[i].q = coord[i].y - coord[0].y;
	}

	// 2. �� ���������� �Ͽ� �ٸ� ������ �ݽð� �������� ���� (���� ����)
	sort(coord + 1, coord + n, compare);

	stack<int> st;

	// 3. ���ÿ� ù��° ������ �ι�° ������ �ش��ϴ� ���� ����
	st.push(0);
	st.push(1);

	int next = 2;

	// 4. ���ÿ��� ������� ������ next ���� ccw �ؼ� > 0���� Ȯ��(��ȸ�� �ϴ���)
	while (next < n)
	{
		while (st.size() >= 2)
		{
			int first, second;
			second = st.top();
			st.pop();
			first = st.top();

			// 5. pop �ߴ� second�� �ٽ� ���ÿ� �ְ� next stack�� ����
			// 6. < 0�̸� (��ȸ��) pop�ߴ� second �� �ְ� �ٽ� ����
			if (ccw(coord[first], coord[second], coord[next]) > 0)
			{
				st.push(second);
				break;
			}
		}

		st.push(next++);
	}

	cout << st.size();
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}