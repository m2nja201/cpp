// ��Ȧ(1865)
// 03.24-03.25.
// �����̶� �ϱ� ������..

#include <iostream>
#include <vector>
#define endl "\n"
#define INF 99999999
using namespace std;

// ������... Ʋ�� ���� : cout�� endl �ȽἭ...

int TC, N, M, W; // �׽�Ʈ ���̽� ����, ���� ��, ���� ��, ��Ȧ ��
//int dist[501];
//vector<bool> answer;

/*
void connect(int a, int b, int c) {
	node[a].push_back({ b, c });
	node[b].push_back({ a, c });
} */

bool travel(vector<pair<int, pair<int, int>>> nodes) {
	int dist[501];
	fill_n(dist, 501, INF);
	dist[1] = 0; // ���� ����(1�� ����)�� �湮�ߴ�. (���Ѵ� -> 0)
	int s, e, t;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < nodes.size(); j++) {
			s = nodes[j].first;
			e = nodes[j].second.first;
			t = nodes[j].second.second;
			if (dist[e] > dist[s] + t) {
				// ������Ʈ
				dist[e] = dist[s] + t;
			}
		}
	}
	// ��� ������Ʈ �� �ð��� �پ���� Ȯ��
	for (int k = 0; k < nodes.size(); k++) {
		s = nodes[k].first;
		e = nodes[k].second.first;
		t = nodes[k].second.second;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> TC;
	int S, E, T;
	
	while (TC--) {
		//fill_n(dist, 501, INF); // ���Ѵ�� �����صα� (TC)��ŭ �ݺ��ؾ� �ϱ� ������ while�ȿ� ����
		vector<pair<int, pair<int, int>>> node; // ���� �굵 �ʱ�ȭ ����� �ؼ� �������� �����߽ú�

		cin >> N >> M >> W;
		//cout << "===========================" << endl;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T; // ���� : ����� ����, ����� ����, �̵� �ð�
			node.push_back({ S, { E, T } });
			node.push_back({ E, { S, T } });
		}
		//cout << "===========================" << endl;
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T; // ��Ȧ : ����, ����, �پ��� �ð�
			node.push_back({ S, { E, -T } }); // ��Ȧ ����
		}

		if (travel(node)) cout << "YES" << endl;
		else cout << "NO" << endl;
		//cout << "===========================" << endl;
	}

	/*for (int i = 0; i < TC; i++) {
		cout << "i = " << i << " ";
		if (answer[i]) cout << "YES";
		else cout << "NO";
	}*/

	return 0;
}