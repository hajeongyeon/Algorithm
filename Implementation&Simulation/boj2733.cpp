#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

map<int, int> looppair;

void Compile(string str)
{
	unsigned char bytearr[32768] = { 0, };

	int ptr = 0;
	int idx = 0;

	while (idx < str.size())
	{
		if (str[idx] == '>')
		{
			ptr++;
			if (ptr > 32767) ptr = 0;
			idx++;
		}
		else if (str[idx] == '<')
		{
			ptr--;
			if (ptr < 0) ptr = 32767;
			idx++;
		}
		else if (str[idx] == '+')
		{
			bytearr[ptr] = (bytearr[ptr] + 1) % 256;
			idx++;
		}
		else if (str[idx] == '-')
		{
			bytearr[ptr] = (bytearr[ptr] - 1 + 256) % 256;
			idx++;
		}
		else if (str[idx] == '.')
		{
			cout << bytearr[ptr];
			idx++;
		}
		else if (str[idx] == '[')
		{
			if (bytearr[ptr] == 0) idx = looppair[idx];
			else idx++;
		}
		else if (str[idx] == ']')
		{
			if (bytearr[ptr] != 0) idx = looppair[idx];
			else
				idx++;
		}
		else
			idx++;
	}
	cout << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	cin.ignore();

	for (int tc = 1; tc <= T; ++tc)
	{
		cout << "PROGRAM #" << tc << ":\n";

		string allstr;			// ��ü ���ڿ�
		stack<int> loop;		// [ ���� ����
		bool flag = false;		// ������ ���� ��� flag

		while (1)
		{
			string tmp;
			getline(cin, tmp);

			if (tmp == "end") break;

			// ���� ����
			tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());

			// �ּ� ����
			if (tmp.find(37) != string::npos)
				tmp.erase(tmp.find(37));

			int curr = 0;		// ���� ����

			// loop ���� ã��
			for (auto c : tmp)
			{
				if (c == '[')
					loop.push(allstr.size() + curr);
				else if (c == ']')
				{
					// loop�� �ƴ϶� ]�� ������
					if (loop.empty())
					{
						flag = true;
						break;
					}

					// looppair(map)�� ¦�� ����
					int idx = loop.top();
					loop.pop();
					looppair.insert({ idx, allstr.size() + curr });
					looppair.insert({ allstr.size() + curr, idx });
				}
				curr++;
			}

			if (flag) break;

			// ���ڿ� ����
			allstr += tmp;
		}

		// [�� �ְų� ]�� ������ compile error
		if (!loop.empty() || flag)
			cout << "COMPILE ERROR\n";
		else
			Compile(allstr);

		// clear
		while (!loop.empty()) loop.pop();
		looppair.clear();
	}
}