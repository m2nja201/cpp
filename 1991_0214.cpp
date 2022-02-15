#include <iostream>
#include <queue>

using namespace std;

struct node { // ����Ʈ���� ���� �⺻ ����
	string position; 
	node* first;
	node* second;
};

struct org_tree {
	node* root;

	// ��Ʈ ��带 �����ϴ� �Լ�
	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const string& value) { // ����(���� ����̰ų� ����Ʈ���� �����Ƿ� ������� Ž��)
		if (root == NULL) return NULL;
		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSub(const string& manager, const string& sub, int LR) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			return false;
		}

		if (managerNode->first && managerNode->second) {
			return false;
		}

		if (!managerNode->first && LR==0) {
			managerNode->first = new node{ sub, NULL, NULL }; // ���� ����Ʈ���� ������ ���ʿ� �߰�
		}
		else if (!managerNode->second && LR == 1) {
			managerNode->second = new node{ sub, NULL, NULL }; // ������ ����Ʈ���� �������� �����ʿ� �߰�
		}
		return true;
	}
};

static void preOrder(node* start) { // preOrde : ������ȸ : ������ -> ���� ���� ��� -> ������ ���� ���
	if (!start) return;

	cout << start->position;
	preOrder(start->first);
	preOrder(start->second);
}

static void inOrder(node* start) { // in-Order : ���� ��ȸ :���� ��� -> ���� ��� -> ������ ���
	if (!start) return;

	inOrder(start->first);
	cout << start->position;
	inOrder(start->second);
}

static void postOrder(node* start) { // post order : ���� ��ȸ : �� �ڽ� ��� ���� �湮 -> ���� ���
	if (!start) return;

	postOrder(start->first);
	postOrder(start->second);
	cout << start->position;
}

int main() {
	int N; // node
	cin >> N;
	string alp[3];
	auto tree = org_tree::create_org_structure("A");

	while (N>0) {
		for (int i = 0; i < 3; i++) {
			cin >> alp[i];
			if (i == 2) {
				if (alp[1] != ".")
					tree.addSub(alp[0], alp[1], 0);
				if (alp[2] != ".")
					tree.addSub(alp[0], alp[2], 1);
			}
			
		}
		N--;
	}

	preOrder(tree.root);
	cout << endl;
	inOrder(tree.root);
	cout << endl;
	postOrder(tree.root);

	return 0;
}