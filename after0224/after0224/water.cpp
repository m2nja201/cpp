// ����(2251)
// 3.10
// ����(��� Ʋ������!)

#include <iostream>
using namespace std;
#define endl "\n"
#include <vector>
#include <algorithm>

int initial[3]; // C is full
int now[3];
vector<int> answer;
bool check[201][201][201] = {false}; // ��� �湮 ����
int turn[6][2] = { {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1} }; // �̰� BFS�� ��� ex: {2, 1} = C���� B�� �� �ű��
int temp[3]; // ��� �����ص� ����

void initialize(string str) {
	if (str == "i") {
		now[0] = 0; now[1] = 0; now[2] = initial[2];
	}
	if (str == "t") {
		now[0] = temp[0]; now[1] = temp[1]; now[2] = temp[2];
	}
}

int act(int depth, int one, int two) { // DFS(��� �������)
	// one : �� �۳��� ��, two : �� �޴� ��

	if (now[one] == 0) return 0; // �� �۳��� ���� ���� ������ �ȵ� 
	if (now[two] == initial[two]) return 0; // �� �޴� ���� ���� ������ �ȵ�

	if (now[one] <= initial[two] - now[two]) {
		now[two] += now[one];
		now[one] = 0; // �� �ξ�~
	}
	else {
		now[one] = now[one] - (initial[two] - now[two]);
		now[two] = initial[two]; // �� ä��~
	}

	if (check[now[0]][now[1]][now[2]] == 1) return 0;
	else check[now[0]][now[1]][now[2]] = 1;

	if (now[0] == 0) { // A ���뿡 �� ������ �信 �ֱ�
		answer.push_back(now[2]);
		// cout << "<<" << now[2] << ">> ";
	}

	for (int j = 0; j < 3; j++) {
		temp[j] = now[j];
	}

	for (int i = 0; i < 6; i++) {
		act(depth + 1, turn[i][0], turn[i][1]);
		// initialize(); <- �������� ��Ȳ ���� �ʱ�ȭ ��Ű�� �ȵǴ°�.....
		initialize("t"); // �׷��� temp�� ���� ���� �ʱ�ȭ ������ϴ±�..!
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> initial[i];
		now[i] = initial[i];
	}

	check[initial[0]][initial[1]][initial[2]] = 1;
	answer.push_back(initial[2]);
	// ������� �ʱ� ����, ���� ����

	for (int i = 4; i < 6; i++) {
		act(0, turn[i][0], turn[i][1]);
		initialize("i");
	}
	sort(answer.begin(), answer.end());
	auto uni = unique(answer.begin(), answer.end());
	answer.erase(uni, answer.end());
	for (auto j : answer) {
		cout << j << " ";
	}

	return 0;
}