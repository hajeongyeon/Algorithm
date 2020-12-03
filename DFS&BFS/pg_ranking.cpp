#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool visited[101];
int cnt[101];
vector<int> winner[101], loser[101];

void DFS_Win(int num)
{
    visited[num] = true;

    for (int i = 0; i < winner[num].size(); ++i)
    {
        if (visited[winner[num][i]]) continue;

        cnt[winner[num][i]]++;
        DFS_Win(winner[num][i]);
    }
}

void DFS_Lose(int num)
{
    visited[num] = true;

    for (int i = 0; i < loser[num].size(); ++i)
    {
        if (visited[loser[num][i]]) continue;

        cnt[loser[num][i]]++;
        DFS_Lose(loser[num][i]);
    }
}

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;

    for (int i = 0; i < results.size(); ++i)
    {
        winner[results[i][0]].push_back(results[i][1]);
        loser[results[i][1]].push_back(results[i][0]);
    }

    for (int i = 1; i <= n; ++i)
    {
        memset(visited, false, sizeof(visited));
        DFS_Win(i);
        memset(visited, false, sizeof(visited));
        DFS_Lose(i);
    }

    // n - 1인 이유 : 당사자 제외한 나머지 사람들의 전적을 안다는 뜻
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == n - 1)
            answer++;

    return answer;
}
