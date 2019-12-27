#include <iostream>
using namespace std;

const int MAX = 101;

int n, l;		// �� ũ��, ����

int checkSt(int idx, int arr[][MAX])
{
	int result;
	int slope[MAX] = { 0, };

	for (int i = 0; i < n - 1; ++i)
	{
		if (arr[idx][i] != arr[idx][i + 1])					// ���̰� �ٸ��� 
		{
			int heightdiff = arr[idx][i + 1] - arr[idx][i];
	
			if (heightdiff != -1 && heightdiff != 1)		// ���� ���̰� 1�� �ƴϸ�
			{
				return 0;
			}
	
			if (heightdiff == 1)		// ���� �Ǵ� ���� ����
			{
				for (int j = 0; j < l; ++j)
				{
					if (i - j < 0) return 0;			// ������ ��� ���
					if (slope[i - j] == 1) return 0;	// ���ΰ� �̹� ������ ���
	
					if (arr[idx][i] == arr[idx][i - j])	// ���θ� ������ �� ���̰� �����ϸ�
						slope[i - j] = 1;				// ���� ��ġ
					else return 0;						// ���θ� ������ �� ���̰� �������� ������
				}
			}
			else if (heightdiff == -1)	// ������ �Ǵ� �Ʒ��� ����
			{
				for (int j = 1; j <= l; ++j)
				{
					if (i + j >= n) return 0;				// ������ ��� ���
					if (slope[i + j] == 1) return 0;		// ���ΰ� �̹� ������ ���
	
					if (arr[idx][i] - 1 == arr[idx][i + j])	// ���θ� ������ �� ���̰� �����ϸ�
						slope[i + j] = 1;					// ���� ��ġ
					else return 0;							// ���θ� ������ �� ���̰� �������� ������
				}
			}
		}
	}

	return 1;		// ��� ������ ����Ѵٸ� ��� + 1
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