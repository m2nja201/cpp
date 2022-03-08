// �̸�Ƽ�� (14226)
// 3.9
// ����

// ��Ʈ : BFS ������ ��� Ǯ�������� �����غ���(�湮 üũ, queue ���)

#include <iostream>
using namespace std;
#include <queue>
#define endl "\n"

int S;
// now : ȭ���� �̸�Ƽ�� ��, store : Ŭ�������� �̸�Ƽ�� ��, times : ���� �ð�
bool check[1001][1001]; // 2<=S<=1000, check[now][store]
queue<pair<pair<int, int>, int >> play; // pair<int, int, int>�� �ȵǴ� ����! {{now, store}, times}

int BFS() {
	play.push({ {1, 0}, 0 }); // 1, 0, 0 (�ʱ�)
	while (!play.empty()) {
		int n = play.front().first.first;
		int s = play.front().first.second;
		int t = play.front().second;
		play.pop();

		if (n == S) {
			return t;
		}

		if (0 < n) {
			// 1. ���� -> check[now][now]�� ������
			// 2. �ٿ��ֱ� -> check[now+store][store]�� ������
			// 3. ���� -> check[now-1][store]�� ������

			if (check[n][n] == 0 && n <= 1000) { 
				play.push({ { n, n }, t + 1 }); // ����
				check[n][n] = 1;
				//cout << "copy! (now n : "<<n<<" )";
			}
			if (s > 0 && s + n <= 1000 && check[n + s][s] == 0) {
				// Ŭ�����忡 ��Ƽ�� �ִٸ�
				play.push({ {s + n, s}, t + 1 }); // �ٿ��ֱ�
				check[s + n][s] = 1;
				//cout << "paste! (now n : " << n << " )";
			}
			if (n<=1000 && check[n - 1][s] == 0) {
				// �ϳ� ���� ���� ���� ��찡 ���� �ʾҴٸ�
				play.push({ {n - 1, s}, t + 1 }); // �����ϱ�
				check[n - 1][s] = 1;
				//cout << "delete! (now n : " << n << " )";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> S;
	check[1][0] = 1;
	cout<< BFS();

	return 0;
}
