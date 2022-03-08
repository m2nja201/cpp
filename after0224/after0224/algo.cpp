// 1261 �˰���
// 3.8
// ����

// ��α� ���� 5% �߽��ϴ�.. (��� ���) �� �ð� ���� ����ϴ� check�� ��� �ؾ��� �� ���� �� �κ� �����߾��

#include <iostream>
#include <queue>
using namespace std;
#define endl "\n"

int M, N; // ����, ���� <- �̰� ���� �򰥸�?? ���⿡ 30�� ¯�� ������,,,
int map[100][100]; // �ִ� 100�̴ϱ� 100���� �γ��ϰ� ������� 2���� �迭 �����Ҵ����� ������� scanf ����ϰŵ���
int turn[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} }; // ��, ��, ��, �� ��
queue<pair<int, int>> que;
int check[100][100]; // �湮�ߴ��� ���� üũ (�⺻ �� : 999999991)

int counting = 0; // �ν� �� ��

void print(); // ��� ���� ����� �迭 �־��� Ȯ���ҷ��� ���� �Ŵϱ� �Ű� �Ƚ�� �˴ϴ�

void BFS() {
	int x = 0; int y = 0; // ���� ���� �� maze, island ������ �������� ���� ��Ź~
	que.push({ x, y });
	check[x][y] = 0;
	while (!que.empty()) {
		x = que.front().first; // ��ġ ����
		y = que.front().second;
		que.pop(); // �ش� ��ġ ���� �� �����

		for (int i = 0; i < 4; i++) {
			int nX = x + turn[i][0];
			int nY = y + turn[i][1]; // ���� ����
			if ((nX >= 0 && nX < M && nY >= 0 && nY < N)) { // ���ο� nx, ny�� ������ ���� �ʰ�
				if (map[nX][nY] == 0) { // ���� ���� ��
					if (check[nX][nY] > check[x][y]) { // �� ���� �� ���� �ƴ϶��
						que.push({ nX, nY }); // �� ��ġ�� ť�� �ְ�,
						check[nX][nY] = check[x][y]; // ���ٴ� ������ check[x][y] ���� �־��ش� (���� �ƴϱ� ������ 1�� ���� �ʿ� X)
					}
				}
				else if (map[nX][nY] == 1) { // ���� ��
					if (check[nX][nY] > check[x][y] + 1) { // ���� ��ġ�� check ������ 1 ũ�ٸ� (�� ���� �ƴ϶��) (1�� �����ִ� ������ ��ġ�� ���� check ���� ��� �����ϰų� ���� ����)
						que.push({ nX, nY }); // �� ��ġ�� ť�� �ְ�
						check[nX][nY] = check[x][y] + 1; // �ν� ���� �� ����
					}
				}
				
			}
			else continue; // ���� ���� ���� ������ ������ ����
		}
	}
	cout << check[M - 1][N - 1]; // ������ ���� ������ �ν� ���� ���� ����Ǿ� ���� ����
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string num;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		for (int j = 0; j < N; j++) {
			// scanf_s("%1d", &map[i][j]); // ���ڿ� ���� ���� ������ ������ ���� ���ڽ��� �̰� ���޴´ٴ�
			map[i][j] = num[j] - '0';
			check[i][j] = 999999991; // �յ��� ū �� �־��ֱ�
		}
	}
	BFS();

	return 0;
}



void print() {
	cout << "------------------" << endl;
	for (int k = 0; k < M; k++) {
		for (int l = 0; l < N; l++) {
			cout << map[l][k] << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}