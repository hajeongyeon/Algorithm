// 2020.05.09
// 프로그래머스 예산

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;

    sort(d.begin(), d.end());

    int tmp = 0;
    for (int i = 0; i < d.size(); ++i)
    {
        if (tmp + d[i] <= budget)
        {
            tmp += d[i];
            answer++;
        }
        else
            break;
    }

    return answer;
}

int main(void)
{
    vector<int> d;
    for (int i = 0; i < 4; ++i)
    {
        int tmp; cin >> tmp;
        d.push_back(tmp);
    }

    int b; cin >> b;

    cout << solution(d, b);
}