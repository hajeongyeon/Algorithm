// 2020.05.09
// 프로그래머스 멀쩡한 사각형

#include <iostream>
using namespace std;

int gcdfunc(int w, int h)
{
    while (h != 0)
    {
        int r = w % h;
        w = h;
        h = r;
    }

    return w;
}

long long solution(int w, int h) 
{
    long long answer = 1;
    int gcd = 0;

    if (w < h) gcd = gcdfunc(h, w);
    else gcd = gcdfunc(w, h);

    answer = (long long)w * (long long)h - (w + h - gcd);

    return answer;
}

int main(void)
{
    int w, h;
    cin >> w >> h;

    cout << solution(w, h);
}