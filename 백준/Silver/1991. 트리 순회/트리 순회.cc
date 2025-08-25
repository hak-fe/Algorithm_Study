#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

typedef struct tree {
	char data;
	struct tree* leftChild;
	struct tree* rightChild;
}tree;

tree* initTree(char root, char left, char right);
void addTree(tree* root, char node, char left, char right);
void prevTraveral(tree* root);
void midTraveral(tree* root);
void postTraveral(tree* root);

int main() {
	FASTIO;
	tree* tree = NULL;
	char node, l, r;
	int n;
	cin >> n;
	cin >> node >> l >> r;

	tree = initTree(node, l, r);

	for (int i = 1; i < n; i++)
	{
		cin >> node >> l >> r;
		addTree(tree, node, l, r);
	}
	prevTraveral(tree);
	cout << endl;
	midTraveral(tree);
	cout << endl;
	postTraveral(tree);
}

tree* initTree(char root, char left, char right) {
	tree* t = (tree*)malloc(sizeof(tree));
	t->data = root;

	if (left == '.')
		t->leftChild = NULL;
	else {
		tree* l = (tree*)malloc(sizeof(tree));
		l->data = left;
		l->leftChild = NULL;
		l->rightChild = NULL;
		t->leftChild = l;

	}
	if (right == '.')
		t->rightChild = NULL;
	else {
		tree* r = (tree*)malloc(sizeof(tree));
		r->data = right;
		r->leftChild = NULL;
		r->rightChild = NULL;
		t->rightChild = r;

	}
	return t;
}
void addTree(tree* root, char node, char left, char right) {
	if (root == NULL) return;

	if (root->data == node) {
		tree* t = root;
		if (left == '.')
			t->leftChild = NULL;
		else {
			tree* l = (tree*)malloc(sizeof(tree));
			l->data = left;
			l->leftChild = NULL;
			l->rightChild = NULL;
			t->leftChild = l;

		}
		if (right == '.')
			t->rightChild = NULL;
		else {
			tree* r = (tree*)malloc(sizeof(tree));
			r->data = right;
			r->leftChild = NULL;
			r->rightChild = NULL;
			t->rightChild = r;

		}
		return;
	}
	addTree(root->leftChild, node, left, right);
	addTree(root->rightChild, node, left, right);
	return;
}
void prevTraveral(tree* root) {
	if (!root)
		return;
	if (root->data != '.')
		cout << root->data;
	prevTraveral(root->leftChild);
	prevTraveral(root->rightChild);
}
void midTraveral(tree* root) {
	if (!root)
		return;
	midTraveral(root->leftChild);
	if (root->data != '.')
		cout << root->data;
	midTraveral(root->rightChild);
}
void postTraveral(tree* root) {
	if (!root)
		return;
	postTraveral(root->leftChild);
	postTraveral(root->rightChild);
	if (root->data != '.')
		cout << root->data;
}