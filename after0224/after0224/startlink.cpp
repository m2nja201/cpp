// ��ŸƮ��ũ(5014)
// 3.14
// ����

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int F, S, G, U, D; // F:�ǹ�����, S:������, G:��ŸƮ��ũ��, U:up, D:down
int check[1000001] = { 0 };
queue<int> que;
vector<int> updown;
int nextf = -1;


int BFS(int st) {
	que.push(st);
	check[st] = 0; // 0���� �����ϴ� ���� => ���� �ִ� ���� �湮�� �� �ƴ����� ��ư ���� Ƚ���� ġ�� �ʱ� ����
	if (st != G) {
		while (!que.empty()) {
			int f = que.front();
			que.pop();
			if (f == G) {
				return check[G]; // ������ ��ŸƮ��ũ ���� check ���� ��ȯ
			}
			// cout << f << " ";
			for (int i = 0; i < 2; i++) {
				nextf = f + updown[i];
				if (nextf == f) continue; // �̰� �ȳ־��༭ ��� Ʋ�Ƚ��ϴ� �� �Ѥ� => u�̳� d�� 0�̸� �ǹ̰� X
				if (0 < nextf && nextf <= F && check[nextf] == 0) {  // up���� �� �ְ����� �ѱ�� X, down ���� �� 0���� �Ǹ� X
					check[nextf] = check[f] + 1; // �̷�ã�� ó�� Ƚ���� ��� �÷��ִ� ����
					que.push(nextf); // nextf������ BFS�� �ض�
				}

			}
		}
		return -1; // use the stairs ��������
	}
	else return check[G]; // ó�� ������ G�� ���ٸ� 0���
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;

	updown.push_back(U);
	updown.push_back(0 - D); // �״ϱ� updown vector�� [0] = up, [1] = down Ű

	int answer = BFS(S);

	if (answer == -1) {
		cout << "use the stairs";
	}
	else {
		cout << answer;
	}

	return 0;
}