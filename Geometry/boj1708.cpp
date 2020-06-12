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

// y좌표, x좌표가 작은 순으로 정렬
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
	// 1. 기준점을 잡는다. (보통 y좌표가 가장 작은 것을 기준으로)
	sort(coord, coord + n, compare);

	for (int i = 1; i < n; ++i)
	{
		coord[i].p = coord[i].x - coord[0].x;
		coord[i].q = coord[i].y - coord[0].y;
	}

	// 2. 이 기준점으로 하여 다른 점들을 반시계 방향으로 정렬 (각에 따라)
	sort(coord + 1, coord + n, compare);

	stack<int> st;

	// 3. 스택에 첫번째 정점과 두번째 정점에 해당하는 값을 넣음
	st.push(0);
	st.push(1);

	int next = 2;

	// 4. 스택에서 순서대로 꺼내고 next 값과 ccw 해서 > 0인지 확인(좌회전 하는지)
	while (next < n)
	{
		while (st.size() >= 2)
		{
			int first, second;
			second = st.top();
			st.pop();
			first = st.top();

			// 5. pop 했던 second를 다시 스택에 넣고 next stack에 넣음
			// 6. < 0이면 (우회전) pop했던 second 안 넣고 다시 진행
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