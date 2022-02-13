// 0213
// adjacency matrix Ȱ���� �׷���
// ��ó : �ڵ� �׽�Ʈ�� ���� �ڷ� ������ �˰��� with c++

// ���� ����� �̿��ϸ� ��� ����*��� ������ ����ϴ� �޸𸮸� ����ϰ� �� => ����
// �̸� �����ϱ� ���� ���� ����Ʈ ����ϸ� ��!

#include <iostream>
#include <vector>
using namespace std;

// enum class �� �����ΰ�? => ������ Ŭ���� (���������� �ʴ�.)
enum class city : int {
	MOSCOW,
	LONDON,
	SEOUL,
	SEATLE,
	DUBAI,
	SYDNEY
};

ostream& operator<<(ostream& os, const city c) { // << ������ ����
	switch (c) {
	case city::LONDON:
		os << "����";
		return os;
	case city::MOSCOW:
		os << "��ũ��";
		return os;
	case city::SEOUL:
		os << "����";
		return os;
	case city::SEATLE:
		os << "�þ�Ʋ";
		return os;
	case city::DUBAI:
		os << "�ι���";
		return os;
	case city::SYDNEY:
		os << "�õ��";
		return os;
	default:
		return os;
	}
}

struct graph {
	vector<vector<int>> data;   // 2����
	graph(int n) { // ������ (������ ���� ���� �׷���)
		data.reserve(n); // n����ŭ ����
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);  // -1�� �ʱ�ȭ

		for (int i = 0; i < n; i++) {
			data.push_back(row);
		}
	}

	void addEdge(const city c1, const city c2, int dis) { // ���� �߰� �Լ�(dis�� ����ġ)
		cout << "���� �߰� : " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1);  // int������ ��ȯ
		auto n2 = static_cast<int>(c2);

		data[n1][n2] = dis; // ����ġ�� �־��ֱ� => �������
		data[n2][n1] = dis; // ������
	}

	void removeEdge(const city c1, const city c2) {
		cout << "���� ���� : " << c1 << "-" << c2 << endl;
		auto n1 = static_cast<int> (c1);
		auto n2 = static_cast<int> (c2);
		data[n1][n2] = -1; // �ʱ���·�
		data[n2][n1] = -1; 
	}
};

int main() {
	graph g(6);  // edge ���� = 6

	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);
	g.addEdge(city::SEATLE, city::LONDON, 8000);

	g.removeEdge(city::SEATLE, city::LONDON);

	return 0;
}