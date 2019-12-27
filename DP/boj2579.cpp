#include <iostream>
#define MAX(a,b) (a > b) ? a : b
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	int* score = new int[num + 1];		// ����
	int* dp = new int[num + 1];			// DP

	for (int i = 1; i <= num; ++i)
	{
		cin >> score[i];
	}

	dp[1] = score[1];
	dp[2] = (score[1] + score[2]);

	// 1. ������ ���� ��� ���� ����� ���� ���
	// 2. ������ ���� ��� ���� ����� ���� ���� ���
	for (int i = 3; i <= num; ++i)
	{
		dp[i] = MAX(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
	}

	cout << dp[num];

	delete[] dp;
	delete[] score;
}