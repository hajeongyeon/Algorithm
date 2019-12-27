#include <iostream>
using namespace std;

const int MAX = 101;

int n, l;		// 맵 크기, 높이

int checkSt(int idx, int arr[][MAX])
{
	int result;
	int slope[MAX] = { 0, };

	for (int i = 0; i < n - 1; ++i)
	{
		if (arr[idx][i] != arr[idx][i + 1])					// 길이가 다르면 
		{
			int heightdiff = arr[idx][i + 1] - arr[idx][i];
	
			if (heightdiff != -1 && heightdiff != 1)		// 높이 차이가 1이 아니면
			{
				return 0;
			}
	
			if (heightdiff == 1)		// 왼쪽 또는 위쪽 경사로
			{
				for (int j = 0; j < l; ++j)
				{
					if (i - j < 0) return 0;			// 범위를 벗어난 경우
					if (slope[i - j] == 1) return 0;	// 경사로가 이미 놓아진 경우
	
					if (arr[idx][i] == arr[idx][i - j])	// 경사로를 놓았을 때 높이가 일정하면
						slope[i - j] = 1;				// 경사로 설치
					else return 0;						// 경사로를 놓았을 때 높이가 일정하지 않으면
				}
			}
			else if (heightdiff == -1)	// 오른쪽 또는 아래쪽 경사로
			{
				for (int j = 1; j <= l; ++j)
				{
					if (i + j >= n) return 0;				// 범위를 벗어난 경우
					if (slope[i + j] == 1) return 0;		// 경사로가 이미 놓아진 경우
	
					if (arr[idx][i] - 1 == arr[idx][i + j])	// 경사로를 놓았을 때 높이가 일정하면
						slope[i + j] = 1;					// 경사로 설치
					else return 0;							// 경사로를 놓았을 때 높이가 일정하지 않으면
				}
			}
		}
	}

	return 1;		// 모든 조건을 통과한다면 결과 + 1
}

int main(void)
{
	cin >> n >> l;

	int col[MAX][MAX], row[MAX][MAX];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> col[i][j];

			row[j][i] = col[i][j];
		}
	}

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		answer += (checkSt(i, col) + checkSt(i, row));
	}

	cout << answer;
}