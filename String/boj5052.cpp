#include <iostream>
#include <cstring>
using namespace std;

char word[10000][11];

class Trie {
private:
	bool isTerminal;
	Trie* children[10];

public:
	Trie() : isTerminal(false) { memset(children, 0, sizeof(children)); }
	~Trie() {
		for (int i = 0; i < 10; ++i)
			if (children[i]) delete children[i];
	}

	void Insert(char* key);
	bool Find(char* key);
};

void Trie::Insert(char* key)
{
	if (*key == '\0') isTerminal = true;
	else
	{
		int idx = *key - '0';

		if (children[idx] == 0) children[idx] = new Trie();

		children[idx]->Insert(key + 1);
	}
}

bool Trie::Find(char* key)
{
	if (*key == 0) return true;
	if (isTerminal) return false;

	int idx = *key - '0';
	return children[idx]->Find(key + 1);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		int n;
		Trie* root = new Trie();
		bool isPossible = true;

		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> word[i];
			root->Insert(word[i]);		}

		for (int i = 0; i < n; ++i)
		{
			if (root->Find(word[i]) == false)
			{
				isPossible = false;
				break;
			}
		}

		delete root;

		if (isPossible) cout << "YES\n";
		else cout << "NO\n";
	}
}