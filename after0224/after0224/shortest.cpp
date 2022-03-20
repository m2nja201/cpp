// �ִܰ�� 1753
// 03.20
// ����

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int V, E, K; // ������ ����, ������ ����, ���� ������ ��ȣ
vector<pair<int, int>> node[300001];
int check[20001] = { 0 };
int length = 0;

void connect(int a, int b, int c) { //  �ֹ��� ������ �ƴϾ���. �������� �� �ڲ� ���� ����ϰ� ������ �ߴ�.
	node[a].push_back({ b, c });
	// node[b].push_back({ a, c }); 
}

void func() { // ���� �տ��� �� �˰����̶� ����ؼ� ���� ������ �� ���� �� ���ƿ��,,,,
	priority_queue<pair<int, int>> pque; // { ���� ����ġ, ������ }
	pque.push({ 0, K }); // K��° �������� ����
	check[K] = 0;

	while (!pque.empty()) {
		int val = - pque.top().first;
		int now = pque.top().second;
		pque.pop();

		for (int i = 0; i < node[now].size(); i++) {
			int nval = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > nval + val) {
				// ū ��� : �鸮�� �ʾ��� ��
				check[next] = nval + val;
				pque.push({ -nval, next });
			}
		}
	}
}

void print() {
	for (int i = 1; i <= V; i++) {
		if (check[i] == 9699999) cout << "INF" << endl;
		else if (i == K) cout << "0" << endl;
		else {
			cout << check[i] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		connect(u, v, w);
	}

	fill_n(check, 20001, 9699999); // check �迭 �ʱ�ȭ

	func();
	print();

	return 0;
}