// hash + math

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;

    unordered_map<string, int> hash;

    // key : 의상의 종류
    for (int i = 0; i < clothes.size(); ++i)
        hash[clothes[i][1]]++;

    // 의상의 종류별로 갯수 + 1(안 입는 것까지)
    for (auto item = hash.begin(); item != hash.end(); ++item)
        answer *= (item->second + 1);

    // 다 안 입는 경우 1을 제외시킴
    answer--;

    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<string>> vec;

    for (int i = 0; i < n; ++i)
    {
        vector<string> tmp;

        for (int j = 0; j < 2; ++j)
        {
            string str; cin >> str;

            tmp.push_back(str);
        }

        vec.push_back(tmp);
    }

    cout << solution(vec);
}
