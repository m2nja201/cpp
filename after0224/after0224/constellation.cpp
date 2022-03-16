// ���ڸ� ����� (4386)
// 03.16
// ���� (BFS�� ����ؼ� ���� ���� �ȴ޾Ҿ��)

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define endl "\n"
using namespace std;

int n; // �� ����
vector<pair<double, double>> pos; // ��ġ(��ǥ)

bool check[101] = { false }; // �湮 �ߴ°�
vector<pair<int, double>> node[101]; // ����� ����, �� �������� �Ÿ� �� �־��� ����
double total = 0;

double distanceCal(double n, double n2, double m, double m2) { // �Ÿ� ������ִ� �Լ�
	double x = n - m;
	double y = n2 - m2;
	double x2py2 = x * x + y * y;
	return sqrt(x2py2);
}

void connect() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = distanceCal(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
			node[i].push_back({ j, dist });
			node[j].push_back({ i, dist }); // �ֹ��� ����
		}
	}
}

void prim() {
	priority_queue<pair<double, int>> pque; // greater�� �Ϸ��� ������ ����� ����ϰ� �ż� - �� �����ϵ��� ��
	for (int i = 0; i < node[0].size(); i++) {
		// ���� ������ 0���� ��´�
		int next = node[0][i].first;
		double dist = node[0][i].second;
		pque.push({ -dist, next }); // �Ÿ��� �� ����� ������ �־��ֱ�;
	}

	check[0] = true; // ù��°������ Ž��
	while (!pque.empty()) {
		double dist = -pque.top().first;
		int now = pque.top().second;
		pque.pop();
		
		if (check[now] == false) {
			check[now] = true; // �湮
			total += dist;
			// cout << "now(dist), total : " << now << "(" << dist << "), " << total << endl;

			for (int i = 0; i < node[now].size(); i++) {
				int next = node[now][i].first;
				double ndist = node[now][i].second;
				if (!check[next]) {
					pque.push({ -ndist, next });
				}
			}
		}
	}
	printf("%0.2f", round(total * 100) / 100.0);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pos.push_back({ x, y });
	}
	connect(); // ����
	prim();

	return 0;
}