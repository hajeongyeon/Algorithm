#include <iostream>
#include <stack>
#include <cstring>
#define MIN(a, b) (a < b) ? a : b
using namespace std;

// �޸� ũ��, ���α׷� �ڵ� ũ��, �Է� ũ��
int sm, sc, si;
// ��ɾ� ����Ƚ��, ������ ��ġ, ���α׷� �Է� �ε���, ���α׷� �ڵ� �ε���
int cnt, pointer, si_idx, sc_idx;
// ���ѷ��� ����
int looppos;

int command(char c, char *Data, char *input)
{
	// modulo 2^8
	if (c == '-')
	{
		Data[pointer] = (Data[pointer] - 1 + 256) % 256;
		sc_idx++;
	}
	else if (c == '+')
	{
		Data[pointer] = (Data[pointer] + 1) % 256;
		sc_idx++;
	}
	// �����͸� �����̴µ�, �迭 ���� �Ѿ�� �ݴ������� �Ѿ
	else if (c == '<')
	{
		pointer = (pointer - 1 + sm) % sm;
		sc_idx++;
	}
	else if (c == '>')
	{
		pointer = (pointer + 1) % sm;
		sc_idx++;
	}
	// loop
	else if (c == '[')
	{
		// ��ɾ� ���� Ƚ�� �Ѿ�� 3 return
		if (cnt >= 50000000 * 2) return 3;
		// ��ɾ� ���� Ƚ�� �Ѿ�� ���ѷ��� ���� ����
		else if (cnt >= 50000000) looppos = MIN(sc_idx, looppos);

		// ]�� ���� -> 1 return
		if (Data[pointer] == 0) return 1;
		else sc_idx++;
	}
	else if (c == ']')
	{
		// [�� ���� -> 2 return
		if (Data[pointer] != 0) return 2;
		else sc_idx++;
	}
	else if (c == '.') sc_idx++;
	else if (c == ',')
	{
		// ���� �ϳ��� �а� �����Ͱ� ����Ű�� ���� ����
		Data[pointer] = input[si_idx];
		if (si_idx < si) si_idx++;
		sc_idx++;
	}

	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;

	for (int test_case = 0; test_case < tc; ++test_case)
	{
		// brainfuck ���α׷�, ���α׷� �Է�, ������ �迭
		char code[4096], input[4097], Data[100000] = { 0, };
		// loop ���� ����
		stack<int> loop;
		// loop pair �迭
		int looppair[4096] = { 0, };

		cin >> sm >> sc >> si >> code >> input;
		input[si] = 255;		// EOF == 255

		cnt = 0, pointer = 0, si_idx = 0, sc_idx = 0;

		// loop ����. ���α׷� �ڵ� ũ�⸸ŭ �ݺ��ϸ鼭 loop�� ã�Ƴ���.
		for (int i = 0; i < sc; ++i)
		{
			if (code[i] == '[') loop.push(i);
			else if (code[i] == ']')
			{
				looppair[i] = loop.top();
				looppair[loop.top()] = i;
				loop.pop();
			}
		}

		bool isInfLoop = false;	// ���ѷ�������
		looppos = sc + 1;

		// ���α׷� �ڵ� �ε����� ���α׷� �ڵ� ũ�⺸�� ������ �ݺ�
		while (sc_idx < sc)
		{
			// ��ɾ� ����
			int result = command(code[sc_idx], Data, input);

			// [
			if (result == 1) sc_idx = looppair[sc_idx] + 1;
			// ]
			else if (result == 2) sc_idx = looppair[sc_idx];
			// ���� ����
			else if (result == 3)
			{
				isInfLoop = true;
				break;
			}

			cnt++;
		}

		if (isInfLoop) cout << "Loops " << looppos << " " << looppair[looppos] << "\n";
		else cout << "Terminates\n";
	}
}