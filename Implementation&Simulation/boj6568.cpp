#include <iostream>
using namespace std;

int main(void)
{
	while (1)
	{
		int memory[32] = { 0, };

		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int bit;

				if (scanf_s("%1d", &bit) == EOF) return 0;

				memory[i] = memory[i] * 2 + bit;
			}
		}

		int PC = 0;
		int Adder = 0;

		while (1)
		{
			int mem = memory[PC];

			int command = mem / 32;
			int operand = mem % 32;

			// HTL
			if (command == 7) break;

			PC = (PC + 1) % 32;

			switch (command)
			{
			case 0:	// STA	
				memory[operand] = Adder;
				break;

			case 1:	// LDA
				Adder = memory[operand];
				break;

			case 2:	// BEQ
				if (!Adder) PC = operand;
				break;

			case 4:	// DEC
				Adder = (Adder + 255) % 256;
				break;

			case 5:	// INC
				Adder = (Adder + 1) % 256;
				break;

			case 6: // JMP
				PC = operand;
				break;
			}
		}

		int idx = 7;
		int answer[8] = { 0, };

		// Adder가 0이 아니면
		if (Adder)
		{
			// 10진수 -> 2진수
			while (1)
			{
				if (Adder == 1)
				{
					answer[idx] = 1;
					break;
				}

				answer[idx] = Adder % 2;
				Adder /= 2;
				idx--;
			}
		}

		for (int i = 0; i < 8; ++i)
			printf("%d", answer[i]);
		printf("\n");
	}
	return 0;
}