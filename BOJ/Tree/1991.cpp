#include <iostream>
#include <string>
#define A 65
using namespace std;

class node {		//트리 노드
public:
	char val;
	node *left, *right;

	node (char val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};
	
void prefix(const node *n) {	//전위식
	if (n == NULL) 
		return;

	cout << (n->val);
	prefix(n->left);
	prefix(n->right);
}

void infix(const node *n) {		//중위식
	if (n == NULL)
		return;

	infix(n->left);
	cout << (n->val);
	infix(n->right);
}

void postfix(const node *n) {	//후위식
	if (n == NULL)
		return;

	postfix(n->left);
	postfix(n->right);
	cout << (n->val);
}

void insert_tree(node *curr, node *l, node *r) {	//트리에 삽입
	curr->left = l;
	curr->right = r;
}

int main() {
	int N;
	char v, l, r;
	node *tree[26];		//26개 알파벳 노드, 0번째 노드가 루트노드
	cin >> N;

	for (int i = 0; i < 26; i++) {
		tree[i] = new node((char)('A' + i));
	}

	while (N--) {
		cin >> v >> l >> r;
		if (l == '.' && r == '.')
			insert_tree(tree[v - A], NULL, NULL);
		else if (r == '.')
			insert_tree(tree[v - A], tree[l - A], NULL);
		else if (l == '.')
			insert_tree(tree[v - A], NULL, tree[r - A]);
		else
			insert_tree(tree[v - A], tree[l - A], tree[r - A]);
	}

	prefix(tree[0]);	cout << "\n";
	infix(tree[0]);		cout << "\n";
	postfix(tree[0]);	cout << "\n";

	for (int i = 0; i < 26; i++) 
		delete tree[i];
}
