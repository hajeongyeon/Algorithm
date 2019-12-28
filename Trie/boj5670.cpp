#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

bool first;
int answer;
char word[100000][81];

class Trie {
public:
	bool isTerminal;	// �ܾ��� ������ ǥ���ϴ� ����
	int cnt;
	Trie* children[26];

public:
	Trie() : isTerminal(false), cnt(0) { memset(children, 0, sizeof(children)); }
	~Trie() {
		for (int i = 0; i < 26; ++i)
			if (children[i]) delete children[i];
	}

	// ���ο� ���ڿ��� Ʈ���̿� �߰��ϴ� �Լ�
	void Insert(char* key);
	// key�� �ش��ϴ� ���ڿ��� ���ξ�� ������ �ִ��� Ȯ���ϴ� �Լ�. ������ ������ �ش� ���ξ ������ �κ��� ��ġ ��ȯ.
	void Find(char* key);
};

void Trie::Insert(char* key)
{
	if (*key == '\0') isTerminal = true;
	else
	{
		int idx = *key - 'a';
		
		// idx�� ����� ���� ������ cnt + 1
		// ���� ��� ù��° �ܾ� hello�� hello ������ idx�� 0�̹Ƿ� cnt�� 1�� �ǰ� ���� �Ҵ�
		// �ι�° �ܾ� hell�� hell ������ idx�� 0�� �ƴϹǷ� �� ���ǹ��� �������� ����
		// ����° �ܾ� heaven�� he������ idx�� 0�� �ƴϹǷ� �Ѿ��, a���ʹ� 0�̹Ƿ� 3��°(a)���� cnt ����
		// �׹�° �ܾ� goodbye�� idx�� 0�̹Ƿ� cnt ����
		if (children[idx] == 0)
		{
			children[idx] = new Trie();
			cnt++;
		}

		children[idx]->Insert(key + 1);
	}
}

void Trie::Find(char* key)
{
	if (*key == 0) return;

	// ù��° ��������
	if (first)
	{
		first = false;
		answer++;
	}
	// ù��° ���ڰ� �ƴϸ�
	else
	{
		// ������ ������ �� answer + 1
		if (isTerminal) answer++;
		// cnt�� 2���� ũ�� �� �� �� �Է��ؾ��ϹǷ� answer + 1
		else if (cnt > 1) answer++;
	}

	int idx = *key - 'a';

	children[idx]->Find(key + 1);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;

	while(cin >> n)
	{
		Trie* root = new Trie();

		answer = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> word[i];
			root->Insert(word[i]);

			cout << root->cnt << endl;
		}

		for (int i = 0; i < n; ++i)
		{
			first = true;
			root->Find(word[i]);
		}

		cout << fixed << setprecision(2) << (double)answer / (double)n << "\n";
		delete root;
	}
}