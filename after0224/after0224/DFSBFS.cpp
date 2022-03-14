// DFS�� BFS(1260)
// 3.13
// ����

#include <iostream>
#include <vector>
#include <queue> // BFS
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M, V; // N:������ ����, M:������ ����, V:����������ȣ
vector<int> node[1001];
int check[1001] = { 0 };
int bnode[1001][1001] = { 0 };
queue<int> que;
int biggest = -1;
int temp = -1;
void connect(int n1, int n2) { // ���� ����� ����
	temp = max(n1, n2);
	biggest = max(biggest, temp); // ���� ū ������ ã�Ƽ� for���� �� �� ȿ�������� ������ ����
	
	node[n1].push_back(n2); // DFS�� ���� ����
	node[n2].push_back(n1);
	bnode[n1][n2] = 1; // BFS�� ���� ����
	bnode[n2][n1] = 1;
}

void DFS(int st) { // st�� �����ϴ� ����
	cout << st << " ";
	check[st] = 1; // �̰��� �� �� �湮�ߴ�
	for (int i = 0; i < node[st].size(); i++) {
		int x = node[st][i]; // x�� st�� ����� ����
		if (check[x] == 0) {
			check[x] = 1; // x�� �湮�߰�
			DFS(x);
		}
	}
}

void BFS(int st) {
	cout << st << " ";
	que.push(st);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0 && bnode[f][i] == 1) {
				// cout << "[" << f << ", " << i << "] ";
				check[f] = 1; // ���࿡ f�� 3, i�� 1 �׷��� 3������ �湮�߰�, 1������ �湮�Ѱ�
				check[i] = 1;
				cout << i << " "; // �湮�� �� ���
				que.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> N >> M >> V;
	int num1, num2;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		connect(num1, num2); // ���� ����ŭ ���� set �ޱ�
	}

	for (int j = 1; j <= biggest; j++) {
		sort(node[j].begin(), node[j].end());
		// �̰� �ϴ� ���� : ������ "�湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�" ��� �Ǿ� �ֱ� ����
		// ���ϰ� �Ǹ� 1243 ���� ���ð� 1423���� ����
	}

	DFS(V);
	fill_n(check, 1001, 0); // DFS�� ��� check�� 0���� ��� �ʱ�ȭ => fill_n(�迭 �̸�, ������, �ʱ�ȭ�� ��);
	cout << endl;
	BFS(V);
	// cout << "!";
	return 0;
}