// 2020.09.11 02:00~02:27
// 백준 7568 덩치
// 구현 (완전 탐색)

#include <iostream>
using namespace std;

int n, score[50];
pair<int, int> ppl[50];

void Solve()
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ppl[i].first < ppl[j].first && ppl[i].second < ppl[j].second)
                score[i]++;
            else if (ppl[i].first > ppl[j].first && ppl[i].second > ppl[j].second)
                score[j]++;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << score[i] + 1 << " ";
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> ppl[i].first >> ppl[i].second;
    }

    Solve();
}
