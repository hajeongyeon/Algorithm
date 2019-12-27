#include <iostream>
using namespace std;

int M, P;
int cube[6][9];

void SideRot(int cubenum, int idx)
{
	if (idx == 1)
	{
		int tmp[4] = { cube[cubenum][0], cube[cubenum][1], cube[cubenum][3], cube[cubenum][6] };

		cube[cubenum][0] = cube[cubenum][2];
		cube[cubenum][1] = cube[cubenum][5];
		cube[cubenum][2] = cube[cubenum][8];
		cube[cubenum][3] = tmp[1];
		cube[cubenum][5] = cube[cubenum][7];
		cube[cubenum][6] = tmp[0];
		cube[cubenum][7] = tmp[2];
		cube[cubenum][8] = tmp[3];
	}
	else
	{
		int tmp[4] = { cube[cubenum][0], cube[cubenum][1], cube[cubenum][2], cube[cubenum][5] };

		cube[cubenum][0] = cube[cubenum][6];
		cube[cubenum][1] = cube[cubenum][3];
		cube[cubenum][2] = tmp[0];
		cube[cubenum][3] = cube[cubenum][7];
		cube[cubenum][5] = tmp[1];
		cube[cubenum][6] = cube[cubenum][8];
		cube[cubenum][7] = tmp[3];
		cube[cubenum][8] = tmp[2];
	}
}

void Rotation(int code)
{
	int dirUD[5] = { 1, 2, 3, 0, 1 };
	int dirLR[5] = { 1, 5, 3, 4, 1 };

	// 1, 2, 3
	if ((code - 1) / 3 == 0)
	{
		if (code == 1) SideRot(4, 1);
		else if (code == 3) SideRot(5, 2);

		int c = (code - 1) % 3;
		int tmp[3] = { cube[1][c], cube[1][c + 3], cube[1][c + 6] };

		for (int i = 0; i < 3; ++i)
		{
			int dir1 = dirUD[i];
			int dir2 = dirUD[i + 1];

			cube[dir1][c] = cube[dir2][c];
			cube[dir1][c + 3] = cube[dir2][c + 3];
			cube[dir1][c + 6] = cube[dir2][c + 6];
		}

		int dir1 = dirUD[3];

		cube[dir1][c] = tmp[0];
		cube[dir1][c + 3] = tmp[1];
		cube[dir1][c + 6] = tmp[2];
	}
	// 4, 5, 6
	else if ((code - 1) / 3 == 1)
	{
		if (code == 4) SideRot(4, 2);
		else if (code == 6) SideRot(5, 1);

		int c = (code - 1) % 3;
		int tmp[3] = { cube[1][c], cube[1][c + 3], cube[1][c + 6] };

		for (int i = 4; i > 1; --i)
		{
			int dir1 = dirUD[i];
			int dir2 = dirUD[i - 1];

			cube[dir1][c] = cube[dir2][c];
			cube[dir1][c + 3] = cube[dir2][c + 3];
			cube[dir1][c + 6] = cube[dir2][c + 6];
		}

		int dir1 = dirUD[1];

		cube[dir1][c] = tmp[0];
		cube[dir1][c + 3] = tmp[1];
		cube[dir1][c + 6] = tmp[2];
	}
	// 7, 8, 9
	else if ((code - 1) / 3 == 2)
	{
		if (code == 7) SideRot(0, 2);
		else if (code == 9) SideRot(2, 1);

		int c = (code - 1) % 3;
		int tmp[3] = { cube[1][c * 3], cube[1][c * 3 + 1], cube[1][c * 3 + 2] };

		for (int i = 0; i < 3; ++i)
		{
			int dir1 = dirLR[i];
			int dir2 = dirLR[i + 1];

			int c2;
			if (c == 0) c2 = 2;
			else if (c == 1) c2 = 1;
			else c2 = 0;

			if (dir1 == 5)
			{
				cube[dir1][c * 3] = cube[dir2][c2 * 3 + 2];
				cube[dir1][c * 3 + 1] = cube[dir2][c2 * 3 + 1];
				cube[dir1][c * 3 + 2] = cube[dir2][c2 * 3];
			}
			else if (dir1 == 3)
			{
				cube[dir1][c2 * 3 + 2] = cube[dir2][c * 3];
				cube[dir1][c2 * 3 + 1] = cube[dir2][c * 3 + 1];
				cube[dir1][c2 * 3] = cube[dir2][c * 3 + 2];
			}
			else
			{
				cube[dir1][c * 3] = cube[dir2][c * 3];
				cube[dir1][c * 3 + 1] = cube[dir2][c * 3 + 1];
				cube[dir1][c * 3 + 2] = cube[dir2][c * 3 + 2];
			}
		}

		int dir1 = dirLR[3];

		cube[dir1][c * 3] = tmp[0];
		cube[dir1][c * 3 + 1] = tmp[1];
		cube[dir1][c * 3 + 2] = tmp[2];
	}
	// 10, 11, 12
	else
	{
		if (code == 10) SideRot(0, 1);
		else if (code == 12) SideRot(2, 2);

		int c = (code - 1) % 3;
		int tmp[3] = { cube[1][c * 3], cube[1][c * 3 + 1], cube[1][c * 3 + 2] };

		for (int i = 4; i > 1; --i)
		{
			int dir1 = dirLR[i];
			int dir2 = dirLR[i - 1];

			int c2;
			if (c == 0) c2 = 2;
			else if (c == 1) c2 = 1;
			else c2 = 0;

			if (dir1 == 4)
			{
				cube[dir1][c * 3] = cube[dir2][c2 * 3 + 2];
				cube[dir1][c * 3 + 1] = cube[dir2][c2 * 3 + 1];
				cube[dir1][c * 3 + 2] = cube[dir2][c2 * 3];
			}
			else if (dir1 == 3)
			{
				cube[dir1][c2 * 3 + 2] = cube[dir2][c * 3];
				cube[dir1][c2 * 3 + 1] = cube[dir2][c * 3 + 1];
				cube[dir1][c2 * 3] = cube[dir2][c * 3 + 2];
			}
			else
			{
				cube[dir1][c * 3] = cube[dir2][c * 3];
				cube[dir1][c * 3 + 1] = cube[dir2][c * 3 + 1];
				cube[dir1][c * 3 + 2] = cube[dir2][c * 3 + 2];
			}
		}

		int dir1 = dirLR[1];

		cube[dir1][c * 3] = tmp[0];
		cube[dir1][c * 3 + 1] = tmp[1];
		cube[dir1][c * 3 + 2] = tmp[2];
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cube[i][j] = i * 9 + j + 1;
		}

		cin >> M;

		for (int i = 0; i < M; ++i)
		{
			int code;
			cin >> code;
			Rotation(code);
		}

		cin >> P;

		cout << "#" << tc;
		for (int i = 0; i < 9; ++i)
			cout << " " << cube[P - 1][i];
		cout << "\n";
	}
}