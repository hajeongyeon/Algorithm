// 2020.05.09
// 프로그래머스 스킬트리

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    int alpha[26] = { 0, };
    for (int i = 0; i < 26; ++i) alpha[i] = -1;
    for (int i = 0; i < skill.size(); ++i)
        alpha[skill[i] - 65] = i;

    for (int i = 0; i < skill_trees.size(); ++i)
    {
        bool flag = false;
        int idx = 0;

        for (int j = 0; j < skill_trees[i].size(); ++j)
        {
            if (alpha[skill_trees[i][j] - 65] == -1) continue;

            if (alpha[skill_trees[i][j] - 65] == idx) idx++;
            else
            {
                flag = true;
                break;
            }
        }

        if (!flag) answer++;
    }

    return answer;
}

int main(void)
{
    string str;
    cin >> str;

    vector<string> skilltree;
    for (int i = 0; i < 4; ++i)
    {
        string tmp; cin >> tmp;
        skilltree.push_back(tmp);
    }

    cout << solution(str, skilltree);
}