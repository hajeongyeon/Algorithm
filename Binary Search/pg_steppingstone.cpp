#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0, left = 0, right = distance;

    sort(rocks.begin(), rocks.end());

    while (left <= right)
    {
        int cnt = 0, prev = 0, mid = (left + right) / 2;

        for (int i = 0; i < rocks.size(); ++i)
        {
            // 현재 돌 - 이전 돌 < mid이면 뒤쪽 돌 제거
            if (rocks[i] - prev < mid) cnt++;
            // prev를 현재 돌로 초기화
            else prev = rocks[i];
        }

        // 마지막 돌과 도착점 사이의 거리 확인
        if (distance - prev < mid) cnt++;

        // 제거한 돌이 n보다 작거나 같으면 더 많은 바위를 제거해야 함
        // 바위 사이 최소 거리의 기준을 높임
        if (cnt <= n)
        {
            answer = mid > answer ? mid : answer;
            left = mid + 1;
        }
        // 바위 제거를 줄여야 함
        // 바위 사이 최소 거리의 기준을 낮춤
        else
            right = mid - 1;
    }

    return answer;
}
