// �ù�(1719)
// 03.22
// ����

#include <iostream>
#define endl "\n"
using namespace std;

int n, m; // �������� ����, �����尣�� ��� ����
int map[201][201] = { 0 }; // ���� ũ�� �ִ� �迭
int check[201][201]; // ù��° ���� ���� �迭

void connect(int a, int b, int c) { //  �ֹ��� ����
	map[a][b] = c;
	map[b][a] = c;

	check[a][b] = b; // a->b �� �� ù��° ������ b��� ģ�� (�� ���� �ٸ� ������ ���ٸ�)
	check[b][a] = a; // b->a �� �� ù��° ������ a��� ģ��
}

void parcel() {
	for (int i = 1; i <= n; i++) { // ���� ������ k->i->j �� �� 
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] > map[i][k] + map[j][i]) {  //  ��, k->j�� ���� ���� ũ�⺸��, i�� ���ļ� �� �� ����ũ�Ⱑ ������
					check[j][k] = check[j][i];  //  �������� i
					map[j][k] = map[i][k] + map[j][i];
				}
			}
		}
	}
}
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << check[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0; // ���� �������� ������ �� �ǹ� X
			else map[i][j] = 99999999; // connect�� �̾����� ���� �������� ���� ũ�⸦ �ִ��
		}
	}

	int A, B, C;  // ������, ������, �ɸ��� �ð�
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		connect(A, B, C);
	}
	parcel();
	print();

	return 0;
}