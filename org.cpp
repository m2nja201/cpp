// 출처 : 코딩테스트를 위한 자료 구조와 알고리즘 with C++
// 0213

#include <iostream>
#include <queue>

using namespace std;

struct node { // 이진트리를 위한 기본 구조
	string position; // 회사의 직책을 나타냄
	node* first;
	node* second;
};

struct org_tree {
	node* root;
	// static node* find(node* root, const string& value);

	// 루트 노드를 생성하는 함수
	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const string& value) { // 팀섹(현재 노드이거나 서브트리에 있으므로 순서대로 탐색)
		if (root == NULL) return NULL;
		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSub(const string& manager, const string& sub) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			cout << manager << "을(를) 찾을 수 없습니다 : " << endl; // 해당 노드가 없다면 서브트리도 만들 수 없음
			return false;
		}

		if (managerNode->first && managerNode->second) {
			// 두 value가 모두 true일 때 = 현재 노드에 sub트리가 두 개 모두 있을 때
			cout << manager << " 아래에 " << sub << "을(를) 추가할 수 없습니다." << endl;
			return false;
		}

		if (!managerNode->first) {
			managerNode->first = new node{ sub, NULL, NULL }; // 왼쪽 서브트리가 없으면 왼쪽에 추가
		}
		else managerNode->second = new node{ sub, NULL, NULL }; // 오른쪽 서브트리가 ㅇ없으면 오른쪽에 추가

		cout << manager << " 아래에 " << sub << "을(를) 추가했습니다. " << endl;

		return true;
	}

	// level order : 현재 노드에 연결되지 않은 노드로 이동 (재귀 사용X)
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

static void preOrder(node* start) { // preOrde : 전위순회 : 현재노드 -> 왼쪽 서브 노드 -> 오른쪽 서브 노드
	if (!start) return;

	cout << start->position << ",";
	preOrder(start->first);
	preOrder(start->second);
}

static void inOrder(node* start) { // in-Order : 중위 순회 :왼쪽 노드 -> 현재 노드 -> 오른쪽 노드
	if (!start) return;

	inOrder(start->first);
	cout << start->position << ", ";
	inOrder(start->second);
}

static void postOrder(node* start) { // post order : 후위 순회 : 두 자식 노드 먼저 방문 -> 현재 노드
	if (!start) return;

	postOrder(start->first);
	postOrder(start->second);
	cout << start->position << ", ";
}



int main() {
	auto tree = org_tree::create_org_structure("CEO"); // root 노드 만들기

	tree.addSub("CEO", "부사장");
	tree.addSub("부사장", "IT부장");
	tree.addSub("IT부장", "보안팀장");
	tree.addSub("부사장", "마케팅부장");
	tree.addSub("마케팅부장", "홍보팀장");
	tree.addSub("홍보팀장", "홍보부원");

	cout << endl << "전위 순회 : ";
	preOrder(tree.root);
	cout << endl << "중위 순회 : ";
	inOrder(tree.root);
	cout << endl << "후위 순회 : ";
	postOrder(tree.root);
	cout << endl << endl;

	tree.levelOrder(tree.root);  
	return 0;
}