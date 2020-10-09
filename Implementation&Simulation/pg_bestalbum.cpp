// 해시

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

// 고유 번호, 재생횟수
struct info {
    int num, plays;
};

bool compareplay(const pair<int, int>& a1, const pair<int, int>& a2)
{
    if (a1.second == a2.second) return a1.first < a2.first;
    return a1.second > a2.second;
}

bool comparegenre(const pair<string, int>& p1, const pair<string, int>& p2)
{
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> rank;
    vector<pair<int, int>> pvec;

    for (int i = 0; i < genres.size(); ++i)
    {
        rank[genres[i]] += plays[i];
        pvec.push_back({ i, plays[i] });
    }

    // 1. 속한 노래가 많이 재생된 장르 찾기
    // (1) map -> vector
    vector<pair<string, int>> vec(rank.begin(), rank.end());
    // (2) sort
    sort(vec.begin(), vec.end(), comparegenre);

    // 2. 장르 내에서 많이 재생된 노래 찾기 -> 재생횟수 같으면 고유번호가 낮을수록
    // (1) 장르 상관 없이 재생 횟수 순으로 정렬
    sort(pvec.begin(), pvec.end(), compareplay);

    // 장르만큼 반복
    // 최대 반복 : 장르 100 * plays 10,000 = 1,000,000
    for (int i = 0; i < vec.size(); ++i)
    {
        // 2개 되면 두번째 반복문 break 시킬 용도
        int cnt = 0;
    
        for (int j = 0; j < pvec.size(); ++j)
        {
            if (vec[i].first == genres[pvec[j].first])
            {
                cnt++;
                answer.push_back(pvec[j].first);
            }

            if (cnt == 2) break;
        }
    }

    return answer;
}
