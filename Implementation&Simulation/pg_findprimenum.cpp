#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> num, tmp;
set<int> save;
bool visited[8];

void Combination(int cnt, int r)
{
    if (cnt == r)
    {
        int idx = 1, sum = 0;
        for (int i = 0; i < tmp.size(); ++i)
        {
            int t = tmp[i];
            for (int j = idx; j < tmp.size(); ++j)
                t *= 10;
            sum += t;
            idx++;
        }
        save.insert(sum);

        return;
    }

    for (int i = 0; i < num.size(); ++i)
    {
        if (visited[i]) continue;
        visited[i] = true;
        tmp.push_back(num[i]);
        Combination(cnt + 1, r);
        tmp.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers)
{
    int answer = 0;

    for (int i = 0; i < numbers.length(); ++i)
    {
        num.push_back(numbers[i] - '0');
        save.insert(numbers[i] - '0');
    }

    for (int i = 2; i <= num.size(); ++i)
        Combination(0, i);

    set<int>::iterator iter;
    for (iter = save.begin(); iter != save.end(); ++iter)
    {
        bool isPrime = true;

        for (int j = 2; j < *iter; ++j)
            if (*iter % j == 0) isPrime = false;

        if (isPrime && *iter != 1 && *iter != 0) answer++;
    }

    return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string num; cin >> num;

    cout << solution(num);
}