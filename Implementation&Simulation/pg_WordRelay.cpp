// 2020.05.09
// 프로그래머스 끝말잇기

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;

    for (int i = 1; i < words.size(); ++i)
    {
        // 1. 이전 단어의 마지막 = 현재 단어의 첫번째
        int prevlen = words[i - 1].length();
        if (words[i - 1][prevlen - 1] != words[i][0])
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }

        // 2. 중복 단어 x
        bool exflag = false;
        for (int j = 0; j < i; ++j)
        {
            if (words[i].length() != words[j].length()) continue;

            bool flag = false;
            for (int k = 0; k < words[i].length(); ++k)
            {
                if (words[i][k] != words[j][k])
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                exflag = true;
                break;
            }
        }

        if (exflag) break;
    }

    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main(void)
{
    int n, len; cin >> n >> len;
    vector<string> words;
    for (int i = 0; i < len; ++i)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }

    vector<int> ans = solution(n, words);
    cout << ans[0] << " " << ans[1];
}