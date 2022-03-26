// Ÿ�Ӹӽ�(11657)
// 03.25.-26.
// ����ʰ��� ����.... ����....? for�� �ȿ��� ���� ���� �� ���� ���µ�........................?

#include <iostream>
#include <vector>
#define endl "\n"
#define INF 99999999
using namespace std;

int N, M; // ���� ����, ���� ����

struct bus {
	int start, end, times; // pair�� ������� �ʰ� struct�� �ϴ� ����� �˰� �Ǿ�� ���׿�
};
vector<bus> buses;

void timemachine() {
	int dist[501];
	fill_n(dist, 501, INF); // INF�� dist �迭 �ʱ�ȭ

	int a, b, c; // ���, ��, �̵� �ð�
	dist[1] = 0; // 1�� ���ð� ����

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < buses.size(); j++) {
			a = buses[j].start;
			b = buses[j].end;
			c = buses[j].times;
			if (dist[a] == INF) continue; // ������Ʈ�� ���ص� �� (INF�ϱ� = �� ���̶� ���� ����(�幮's coding world �������� ���� �� ����)
			if (dist[b] > dist[a] + c) {
				dist[b] = dist[a] + c; // ������Ʈ (��Ȧ�̶� ���� ����)
			}
		}
	}

	for (int k = 0; k < buses.size(); k++) {
		a = buses[k].start;
		b = buses[k].end;
		c = buses[k].times;
		if (dist[a] == INF) continue; // ������Ʈ�� ���ص� �� (INF�ϱ� = �� ���̶� ���� ����(�幮's coding world �������� ���� �� ����)
		if (dist[b] > dist[a] + c) {
			cout << "-1" << endl; // ��Ȧ ������ �ð��� ���� �� ���� ���� �ڵ� => Ÿ�Ӹӽ� ���������� ������ ���� ������ �ǵ��� �� ���� ��
			return; // -1�� ����ϰ� ����
		}
	}

	for (int i = 2; i <= N; i++) {
		//  N-1���� ���� ���, 1 �����ÿ��� �����~ ��� ���ֱ� ������ 2�� ���ú��� Ž�����ָ� ��
		if (dist[i] == INF) {
			cout << "-1" << endl; // �ش� ���÷� ���� ��ΰ� ����
		}
		else cout << dist[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		buses.push_back({ A, B, C });
	}
	
	timemachine();

	return 0;
}