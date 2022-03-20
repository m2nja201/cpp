// ������ (1446)
// 3.20
// ����

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, D; // �������� ����, ��ӵ����� ����
vector<pair<int, int>> node[10001];
int check[10001];

int minLen = 0;
int here = 0;

void connect(int s, int e, int l) {
	// s:����, e:��, l:����
	node[e].push_back({ s, l });
	// node[s].push_back({ e, l }); �ֹ����� �ȵ� ������ �ȵǰŵ�
}

void algo() {
	check[0] = 0; // ���� �湮

	for (int i = 1; i <= D; i++) { // �׵��� ������ ������ �ٸ� ���� while�� �Ƚᵵ �ȴٴ� �� => �׳� �񱳸� �ص� �Ǵ� �Ŷ�
		if (node[i].size() == 0) {
			check[i] = check[i - 1] + 1; // ������ ������ �׳� ���ϸ� �Ǵ� ��
			// cout << check[i]<< " ";
		}
		else {
			for (int j = 0; j < node[i].size(); j++) {
				check[i] = min(check[i], check[i - 1] + 1); // (1) �׳� ���� �� �� ������
				check[i] = min(check[i], check[node[i][j].first] + node[i][j].second); // (2) ���������� ���� ���Ѱ� �� ������ 
				// cout << check[i] << "(" << i << ", " << j << ") ";
			}
		}
	}
	cout << check[D]; // ������������ ���� ����
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> N >> D;
	fill_n(check, 10001, 9999999);
	int start, end, length;
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> length;
		if (end > D) continue;  // ���� �������� �� �� �� : �����濡 �ش� X
		connect(start, end, length);
	}
	algo();

	return 0;
}