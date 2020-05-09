#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;

    //
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        // 1번
        if (answers[i] == i % 5 + 1) a++;
        
        // 2번
        if ((i % 2 == 0) && (answers[i] == 2)) b++;
        else if (i % 2 == 1)
        {
            if ((i % 8 == 1) && (answers[i] == 1)) b++;
            else if ((i % 8 == 3) && (answers[i] == 3)) b++;
            else if ((i % 8 == 5) && (answers[i] == 4)) b++;
            else if ((i % 8 == 7) && (answers[i] == 5)) b++;
        }

        // 3번
        if ((i % 10 == 0 || i % 10 == 1) && answers[i] == 3) c++;
        else if ((i % 10 == 2 || i % 10 == 3) && answers[i] == 1) c++;
        else if ((i % 10 == 4 || i % 10 == 5) && answers[i] == 2) c++;
        else if ((i % 10 == 6 || i % 10 == 7) && answers[i] == 4) c++;
        else if ((i % 10 == 8 || i % 10 == 9) && answers[i] == 5) c++;
    }

    if (a == b)
    {
        if (b == c)
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(b < c) answer.push_back(3);
        else if (b > c)
        {
            answer.push_back(1);
            answer.push_back(2);
        }
    }
    else if (a == c)
    {
        if (c < b) answer.push_back(2);
        else if (c > b)
        {
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else if (b == c)
    {
        if (c < a) answer.push_back(1);
        else if (c > a)
        {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    else if (a > b && a > c) answer.push_back(1);
    else if (b > a && b > c) answer.push_back(2);
    else if (c > a && c > b) answer.push_back(3);

    return answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    vector<int> tmp;
    for (int i = 0; i < 5; ++i)
    {
        int a; cin >> a;
        tmp.push_back(a);
    }

    vector<int> ans;
    ans = solution(tmp);

    if (ans.size() == 1) cout << ans[0];
    else if (ans.size() == 3) cout << "모든 사람\n";
}