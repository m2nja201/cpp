// ���ΰ˹�(2307)
// 03.23
// ����

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, M; // ������ ��, ������ ��
int check[1001];
vector<pair<int, int>> node[5001];
vector<pair<int, int>> visited; // �ִ� ��ο� ���� ��� �����ϵ���
int origin = 0;

void connect(int aa, int bb, int cc) {
	// �����
	node[aa].push_back({ bb, cc });
	node[bb].push_back({ aa, cc });
}

void road() {
	priority_queue<pair<int, int>> pq; // { -�ð�, ���� ���� }
	pq.push({ 0, 1 }); // 1�� �������� ����
	check[1] = 0; // 1�� ������ �湮

	while (!pq.empty()) {
		int time = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (now == N) return; // �� ��忡 �湮��

		for (int i = 0; i < node[now].size(); i++) {
			int ntime = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > check[now] + ntime) { // �� ���� ���� = now�� ���� next ������ ���� ����
				visited.push_back({ now, next }); // �湮�� ���� �����صα� (�ִ� ��� ã�� �� �湮�� ���� �߿��� ������ �Ǵϱ�)
				check[next] = check[now] + ntime;
				pq.push({ -check[next], next});
			}
		}
	}
}

void closingroad(int from, int to) {
	priority_queue<pair<int, int>> cpq;
	cpq.push({ 0, 1 });
	check[1] = 0;
	while (!cpq.empty()) {
		int time = -cpq.top().first;
		int now = cpq.top().second;
		cpq.pop();

		if (now == N) return; // �� ������ �����ϸ� ��

		for (int i = 0; i < node[now].size(); i++) { // �� �Լ��� ���� ����
			int ntime = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > check[now] + ntime) {
				if (!(from == now && to == next) && !(from == next && to == from)) {
					check[next] = check[now] + ntime;
					cpq.push({ -check[next], next });
					//cout << now << " -> " << next << endl;
				}
			}
		}
	}
	//cout << "----------------" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	/////////////// �Է�
	cin >> N >> M;
	int a, b, t;
	pair<int, pair<int, int>> here = { 10000, {1, 1} }; // { �ð�, ����from, ����to } => �ð��� ��������, ������ Ŭ���� here�� ������Ʈ
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		connect(a, b, t);
	}

	/////////////// �˹� �� �ִ� �ð�
	fill_n(check, 1001, 99999999); // check �ʱ�ȭ
	road();
	if (check[N] == 99999999) {
		//cout << "�����";
		cout << "0";
		return 0; // �� �� ���� �� 0
	} // �˹� ���� �ʾ��� �� �ִܽð�
	else {
		origin = check[N];
	}

	//////////////// �˹� �� �����ð�
	int answer = 0;
	for (int i = 0; i < visited.size(); i++) {
		//cout << endl << visited[i].first << ", " << visited[i].second << " : " << endl;
		fill_n(check, 1001, 99999999);  // check �ʱ�ȭ
		closingroad(visited[i].first, visited[i].second);
		if (check[N] == 99999999) {
			cout << "-1";
			return 0;
		}
		//cout << check[N] << " ";
		answer = max(answer, check[N] - origin); // max�� ���� : �����ð��� �ִ뿩�� �ϱ� ����
	}
	
	cout << answer;

	return 0;
}