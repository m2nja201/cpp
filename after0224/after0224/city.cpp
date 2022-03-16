// ���� ��Ȱ ��ȹ(1647)
// 3.16
// ����

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, M; // ���� ����, ���� ����
vector<pair<int, int>> node[100001];
bool check[100001] = { false };
int fee = 0;
int com = 0;
int last = 1;

void connect(int a, int b, int c) { //  �ֹ��� ����
	node[a].push_back({b, c});
	node[b].push_back({ a, c });
}

void prim() {
	// ���� �� 1���� 3���� ���� ����Ǿ� �ִٰ� �� ��, �� ���� ���� ������ 4, 2, 3�̸� ������ 2�� �游 ���ΰ� ������ �� ���ֱ�
	priority_queue<pair<int, int>> pque;
	for (int i = 0; i < node[1].size(); i++) { // node[1]�� ������ ���� ������ ����� ���� ���������� 1<=A, B<=N�̱� ����
		pque.push({ -node[1][i].second, node[1][i].first }); // ������, ����� �� ���� pque�� �ֱ�
	}
	check[1] = true; // ��� ����~
	while (!pque.empty()) {
		int cost = -pque.top().first;
		int house = pque.top().second;
		pque.pop();

		if (!check[house]) {
			check[house] = true;
			// ������ �� ���� ���� �� �� ������ �� ���� �־ �Ǵϱ� ���� ������ ū ���� �ϵ�
			com = max(com, cost); // ���� ū ������ �����

			fee += cost;
			for (int i = 0; i < node[house].size(); i++) {
				int neighbor = node[house][i].first;
				int ncost = node[house][i].second;
				if (!check[neighbor]) pque.push({ -ncost, neighbor });
			}
		}
	}
	cout << fee - com;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int A, B, C; // ��, ��, �� �� �����ϴ� ���� ������
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		connect(A, B, C);
	}
	prim();
	return 0;
}