#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

bool first;
int answer;
char word[100000][81];

class Trie {
public:
	bool isTerminal;	// 단어의 끝임을 표시하는 변수
	int cnt;
	Trie* children[26];

public:
	Trie() : isTerminal(false), cnt(0) { memset(children, 0, sizeof(children)); }
	~Trie() {
		for (int i = 0; i < 26; ++i)
			if (children[i]) delete children[i];
	}

	// 새로운 문자열을 트라이에 추가하는 함수
	void Insert(char* key);
	// key에 해당하는 문자열을 접두어로 가지고 있는지 확인하는 함수. 가지고 있으면 해당 접두어가 끝나는 부분의 위치 반환.
	void Find(char* key);
};

void Trie::Insert(char* key)
{
	if (*key == '\0') isTerminal = true;
	else
	{
		int idx = *key - 'a';
		
		// idx에 저장된 것이 없으면 cnt + 1
		// 예를 들어 첫번째 단어 hello는 hello 각각의 idx가 0이므로 cnt가 1이 되고 동적 할당
		// 두번째 단어 hell은 hell 각각의 idx가 0이 아니므로 이 조건문을 만족하지 않음
		// 세번째 단어 heaven은 he까지는 idx가 0이 아니므로 넘어가고, a부터는 0이므로 3번째(a)부터 cnt 증가
		// 네번째 단어 goodbye는 idx가 0이므로 cnt 증가
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

	// 첫번째 글자인지
	if (first)
	{
		first = false;
		answer++;
	}
	// 첫번째 글자가 아니면
	else
	{
		// 마지막 글자일 때 answer + 1
		if (isTerminal) answer++;
		// cnt가 2보다 크면 한 번 더 입력해야하므로 answer + 1
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