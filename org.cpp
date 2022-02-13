// ��ó : �ڵ��׽�Ʈ�� ���� �ڷ� ������ �˰��� with C++
// 0213

#include <iostream>
#include <queue>

using namespace std;

struct node { // ����Ʈ���� ���� �⺻ ����
	string position; // ȸ���� ��å�� ��Ÿ��
	node* first;
	node* second;
};

struct org_tree {
	node* root;
	// static node* find(node* root, const string& value);

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

	bool addSub(const string& manager, const string& sub) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			cout << manager << "��(��) ã�� �� �����ϴ� : " << endl; // �ش� ��尡 ���ٸ� ����Ʈ���� ���� �� ����
			return false;
		}

		if (managerNode->first && managerNode->second) {
			// �� value�� ��� true�� �� = ���� ��忡 subƮ���� �� �� ��� ���� ��
			cout << manager << " �Ʒ��� " << sub << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}

		if (!managerNode->first) {
			managerNode->first = new node{ sub, NULL, NULL }; // ���� ����Ʈ���� ������ ���ʿ� �߰�
		}
		else managerNode->second = new node{ sub, NULL, NULL }; // ������ ����Ʈ���� �������� �����ʿ� �߰�

		cout << manager << " �Ʒ��� " << sub << "��(��) �߰��߽��ϴ�. " << endl;

		return true;
	}

	// level order : ���� ��忡 ������� ���� ���� �̵� (��� ���X)
	static void levelOrder(node* start) {
		if (!start) return;

		queue<node*> q;
		q.push(start);

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front();
				q.pop();

				cout << current->position << ", ";
				if (current->first) q.push(current->first);
				if (current->second) q.push(current->second);
			}
			cout << endl;
		}
	}
};

static void preOrder(node* start) { // preOrde : ������ȸ : ������ -> ���� ���� ��� -> ������ ���� ���
	if (!start) return;

	cout << start->position << ",";
	preOrder(start->first);
	preOrder(start->second);
}

static void inOrder(node* start) { // in-Order : ���� ��ȸ :���� ��� -> ���� ��� -> ������ ���
	if (!start) return;

	inOrder(start->first);
	cout << start->position << ", ";
	inOrder(start->second);
}

static void postOrder(node* start) { // post order : ���� ��ȸ : �� �ڽ� ��� ���� �湮 -> ���� ���
	if (!start) return;

	postOrder(start->first);
	postOrder(start->second);
	cout << start->position << ", ";
}



int main() {
	auto tree = org_tree::create_org_structure("CEO"); // root ��� �����

	tree.addSub("CEO", "�λ���");
	tree.addSub("�λ���", "IT����");
	tree.addSub("IT����", "��������");
	tree.addSub("�λ���", "�����ú���");
	tree.addSub("�����ú���", "ȫ������");
	tree.addSub("ȫ������", "ȫ���ο�");

	cout << endl << "���� ��ȸ : ";
	preOrder(tree.root);
	cout << endl << "���� ��ȸ : ";
	inOrder(tree.root);
	cout << endl << "���� ��ȸ : ";
	postOrder(tree.root);
	cout << endl << endl;

	tree.levelOrder(tree.root);  
	return 0;
}