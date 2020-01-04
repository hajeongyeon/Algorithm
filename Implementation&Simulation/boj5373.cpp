#include <iostream>
#include <string>
using namespace std;

char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
enum { WHITE = 0, YELLOW = 1, RED = 2, ORANGE = 3, GREEN = 4, BLUE = 5 };

char cube[6][3][3];

void Init()
{
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				cube[i][j][k] = color[i];
}

void selfRotation(int c)
{
	char tmp[3][3] =
	{
		{cube[c][2][0], cube[c][1][0], cube[c][0][0]},
		{cube[c][2][1], cube[c][1][1], cube[c][0][1]},
		{cube[c][2][2], cube[c][1][2], cube[c][0][2]}
	};

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cube[c][i][j] = tmp[i][j];
}

void rotation(char face)
{
	if (face == 'U')
	{
		selfRotation(WHITE);
		char tmp1 = cube[RED][0][0];
		char tmp2 = cube[RED][0][1];
		char tmp3 = cube[RED][0][2];
		cube[RED][0][0] = cube[BLUE][2][0];
		cube[RED][0][1] = cube[BLUE][1][0];
		cube[RED][0][2] = cube[BLUE][0][0];
		cube[BLUE][2][0] = cube[ORANGE][2][2];
		cube[BLUE][1][0] = cube[ORANGE][2][1];
		cube[BLUE][0][0] = cube[ORANGE][2][0];
		cube[ORANGE][2][2] = cube[GREEN][0][2];
		cube[ORANGE][2][1] = cube[GREEN][1][2];
		cube[ORANGE][2][0] = cube[GREEN][2][2];
		cube[GREEN][0][2] = tmp1;
		cube[GREEN][1][2] = tmp2;
		cube[GREEN][2][2] = tmp3;
	}
	else if (face == 'D')
	{
		selfRotation(YELLOW);
		char tmp1 = cube[RED][2][2];
		char tmp2 = cube[RED][2][1];
		char tmp3 = cube[RED][2][0];
		cube[RED][2][2] = cube[GREEN][2][0];
		cube[RED][2][1] = cube[GREEN][1][0];
		cube[RED][2][0] = cube[GREEN][0][0];
		cube[GREEN][2][0] = cube[ORANGE][0][0];
		cube[GREEN][1][0] = cube[ORANGE][0][1];
		cube[GREEN][0][0] = cube[ORANGE][0][2];
		cube[ORANGE][0][0] = cube[BLUE][0][2];
		cube[ORANGE][0][1] = cube[BLUE][1][2];
		cube[ORANGE][0][2] = cube[BLUE][2][2];
		cube[BLUE][0][2] = tmp1;
		cube[BLUE][1][2] = tmp2;
		cube[BLUE][2][2] = tmp3;
	}
	else if (face == 'F')
	{
		selfRotation(RED);
		char tmp1 = cube[WHITE][2][0];
		char tmp2 = cube[WHITE][2][1];
		char tmp3 = cube[WHITE][2][2];
		cube[WHITE][2][0] = cube[GREEN][2][0];
		cube[WHITE][2][1] = cube[GREEN][2][1];
		cube[WHITE][2][2] = cube[GREEN][2][2];
		cube[GREEN][2][0] = cube[YELLOW][2][0];
		cube[GREEN][2][1] = cube[YELLOW][2][1];
		cube[GREEN][2][2] = cube[YELLOW][2][2];
		cube[YELLOW][2][0] = cube[BLUE][2][0];
		cube[YELLOW][2][1] = cube[BLUE][2][1];
		cube[YELLOW][2][2] = cube[BLUE][2][2];
		cube[BLUE][2][0] = tmp1;
		cube[BLUE][2][1] = tmp2;
		cube[BLUE][2][2] = tmp3;
	}
	else if (face == 'B')
	{
		selfRotation(ORANGE);
		char tmp1 = cube[WHITE][0][0];
		char tmp2 = cube[WHITE][0][1];
		char tmp3 = cube[WHITE][0][2];
		cube[WHITE][0][0] = cube[BLUE][0][0];
		cube[WHITE][0][1] = cube[BLUE][0][1];
		cube[WHITE][0][2] = cube[BLUE][0][2];
		cube[BLUE][0][0] = cube[YELLOW][0][0];
		cube[BLUE][0][1] = cube[YELLOW][0][1];
		cube[BLUE][0][2] = cube[YELLOW][0][2];
		cube[YELLOW][0][0] = cube[GREEN][0][0];
		cube[YELLOW][0][1] = cube[GREEN][0][1];
		cube[YELLOW][0][2] = cube[GREEN][0][2];
		cube[GREEN][0][0] = tmp1;
		cube[GREEN][0][1] = tmp2;
		cube[GREEN][0][2] = tmp3;
	}
	else if (face == 'L')
	{
		selfRotation(GREEN);
		char tmp1 = cube[WHITE][0][0];
		char tmp2 = cube[WHITE][1][0];
		char tmp3 = cube[WHITE][2][0];
		cube[WHITE][0][0] = cube[ORANGE][0][0];
		cube[WHITE][1][0] = cube[ORANGE][1][0];
		cube[WHITE][2][0] = cube[ORANGE][2][0];
		cube[ORANGE][0][0] = cube[YELLOW][2][2];
		cube[ORANGE][1][0] = cube[YELLOW][1][2];
		cube[ORANGE][2][0] = cube[YELLOW][0][2];
		cube[YELLOW][2][2] = cube[RED][0][0];
		cube[YELLOW][1][2] = cube[RED][1][0];
		cube[YELLOW][0][2] = cube[RED][2][0];
		cube[RED][0][0] = tmp1;
		cube[RED][1][0] = tmp2;
		cube[RED][2][0] = tmp3;
	}
	else if (face == 'R')
	{
		selfRotation(BLUE);
		char tmp1 = cube[WHITE][0][2];
		char tmp2 = cube[WHITE][1][2];
		char tmp3 = cube[WHITE][2][2];
		cube[WHITE][0][2] = cube[RED][0][2];
		cube[WHITE][1][2] = cube[RED][1][2];
		cube[WHITE][2][2] = cube[RED][2][2];
		cube[RED][0][2] = cube[YELLOW][2][0];
		cube[RED][1][2] = cube[YELLOW][1][0];
		cube[RED][2][2] = cube[YELLOW][0][0];
		cube[YELLOW][2][0] = cube[ORANGE][0][2];
		cube[YELLOW][1][0] = cube[ORANGE][1][2];
		cube[YELLOW][0][0] = cube[ORANGE][2][2];
		cube[ORANGE][0][2] = tmp1;
		cube[ORANGE][1][2] = tmp2;
		cube[ORANGE][2][2] = tmp3;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		Init();

		int n; cin >> n;

		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;

			if (str[1] == '+') rotation(str[0]);
			else for (int j = 0; j < 3; ++j) rotation(str[0]);
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << cube[0][i][j];
			}
			cout << "\n";
		}
	}
}