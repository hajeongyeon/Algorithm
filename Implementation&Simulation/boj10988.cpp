#include <iostream>
#include <string>
using namespace std;

string str;

int Palindrome(int s, int e)
{
	if (s >= e) return 1;
	if (str[s] != str[e]) return 0;

	return Palindrome(s + 1, e - 1);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> str;

	if(!Palindrome(0, str.length() - 1)) cout << "0";
	else cout << "1";
}