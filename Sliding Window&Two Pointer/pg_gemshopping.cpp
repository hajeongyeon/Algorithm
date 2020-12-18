#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer(2);
    int left = 0, right = 1, gemNum = 0, minDist = 1e9;
    map<string, int> mapGems;

    for (int i = 0; i < gems.size(); ++i)
        mapGems[gems[i]] += 1;

    gemNum = mapGems.size();
    mapGems.clear();

    mapGems[gems[0]]++;

    while (1)
    {
        if (gemNum == mapGems.size())
        {
            if (minDist > right - left)
            {
                minDist = right - left;
                answer[0] = left + 1;
                answer[1] = right;
            }

            if (mapGems[gems[left]] == 1) mapGems.erase(gems[left]);
            else mapGems[gems[left]]--;

            left++;
        }
        else if (right == gems.size())
            break;
        else
        {
            mapGems[gems[right]]++;
            right++;
        }
    }

    return answer;
}
