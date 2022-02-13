// 0213
// adjacency matrix 활용한 그래프
// 출처 : 코딩 테스트를 위한 자료 구조와 알고리즘 with c++

// 인접 행렬을 이용하면 노드 개수*노드 개수에 비례하는 메모리를 사용하게 됨 => 단점
// 이를 보완하기 위해 인접 리스트 사용하면 됨!

#include <iostream>
#include <vector>
using namespace std;

// enum class 는 무엇인가? => 열거형 클래스 (안전하지는 않다.)
enum class city : int {
	MOSCOW,
	LONDON,
	SEOUL,
	SEATLE,
	DUBAI,
	SYDNEY
};

ostream& operator<<(ostream& os, const city c) { // << 연산자 정의
	switch (c) {
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;
	}
}

struct graph {
	vector<vector<int>> data;   // 2차원
	graph(int n) { // 생성자 (에지가 전혀 없는 그래프)
		data.reserve(n); // n개만큼 공간
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);  // -1로 초기화

		for (int i = 0; i < n; i++) {
			data.push_back(row);
		}
	}

	void addEdge(const city c1, const city c2, int dis) { // 엣지 추가 함수(dis는 가중치)
		cout << "엣지 추가 : " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1);  // int형으로 변환
		auto n2 = static_cast<int>(c2);

		data[n1][n2] = dis; // 가중치로 넣어주기 => 인접행렬
		data[n2][n1] = dis; // 무방향
	}

	void removeEdge(const city c1, const city c2) {
		cout << "엣지 삭제 : " << c1 << "-" << c2 << endl;
		auto n1 = static_cast<int> (c1);
		auto n2 = static_cast<int> (c2);
		data[n1][n2] = -1; // 초기상태로
		data[n2][n1] = -1; 
	}
};

int main() {
	graph g(6);  // edge 개수 = 6

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