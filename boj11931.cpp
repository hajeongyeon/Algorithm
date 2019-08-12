#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int arr[1000000];

bool desc(int a, int b)
{
	return a > b;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
}