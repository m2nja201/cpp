// ��Ʈ��ũ ����(1922)
// 3.18
// ����

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl "\n"

int N, M; //��ǻ���� ��, ���� ��
vector<pair<int, int>> node[100001]; // {����� ����, ���}
bool check[100001] = { false };
int total = 0;

void connect(int a, int b, int c) { //  �ֹ��� ����
	node[a].push_back({ b, c });
	node[b].push_back({ a, c });
}

void prim() {
	priority_queue<pair<int, int>> pque;
	for (int i = 0; i < node[1].size(); i++) { // node[1]�� ���� : ���ʹ� 1������ ����(0�� X)
		pque.push({ -node[1][i].second, node[1][i].first }); // {-���, ����} => -�� �־ ����
		// �� ���� ��� ��� ���ͺ��� �湮 => �� ������ check�� true�� �Ǿ �ٽ� �湮 X
	}
	check[1] = true; // �� ���� �����
	while (!pque.empty()) {
		int cost = -pque.top().first;
		int com = pque.top().second;
		pque.pop();

		if (!check[com]) {
			check[com] = true;
			total += cost;

			for (int i = 0; i < node[com].size(); i++) {
				int next = node[com][i].first;
				int ncost = node[com][i].second;
				if (!check[next]) pque.push({ -ncost, next });
			}
		}
	}
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> N >> M;

	int aa, bb, cc; // for������ ���� ����, ����, ���
	for (int i = 0; i < M; i++) {
		cin >> aa >> bb >> cc;
		connect(aa, bb, cc);
	}
	prim();

	return 0;
}