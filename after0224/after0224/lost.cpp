// �Ҿ���� ��ȣ(1541)
// 03.06
// ����

#include <iostream>
using namespace std;
#define endl "\n"
#include <vector>
#include <string>

string equation;
vector<string> ope;

// ������ sep�Լ��� sub�Լ��� Ǯ���� �ߴµ� �����غ��� �� ���ͷ� ������ �־��� �����ļ�
// sub2 �Լ��� �������ϴ�?
// �ٵ� ���� �Լ��ε� ������ �� �� �����µ� �������� �𸣰����� Ʋ�Ƚ��ϴ� �� �ߴ��󱸿�

void sep(string equ) { // ����, ������ ���ͷ� �����ִ� �Լ������
	string str = "";
	int start = -1;
	int end = 0;
	for (int i = 0; i < equ.length(); i++) {
		if (equ[i] >= 48 && equ[i] <= 57) {
			if (start == -1) {
				start = i;
			}
			else {
				if (equ[i + 1] == 43 || equ[i + 1] == 45 || (i == equ.length() - 1)) {
					end = i;
					ope.push_back(equ.substr(start, end - start + 1));
				}
			}
		}
		else {
			start = -1;
			if (equ[i] == '-') ope.push_back("-");
			else ope.push_back("+");	
		}
	}
}

int sub(string equ) {
	sep(equ);
	int answer = 0;
	int temp = 0;
	bool flag = false;
	for (int i = 0; i < ope.size(); i++) {
		if (ope[i] == "-") {
			flag = true;
			answer -= temp;
			temp = 0;
		}
		else {
			if (ope[i] == "+") continue;
			if (flag) {
				temp += stoi(ope[i]);
			}
			else {
				answer += stoi(ope[i]);
			}
			if (i == ope.size() - 1) answer -= temp;
		}
	}
	return answer;
}

int sub2(string equ) {
	bool flag = false; // -�̸� true
	int answer = 0;
	string temp = ""; // -�϶� -���� ���ڵ��� �־��ִ� ����
	for (int i = 0; i < equ.length(); i++) {
		if (equ[i] == '-' || equ[i] == '+') {
			if (flag) { // -��
				answer -= stoi(temp); // ��Ƶ� ���� �� ���ֱ�
				temp = "";
			}
			else {
				answer += stoi(temp); // ��Ƶ� ���� �����ֱ� (ó�� - ������ �� ����)
				temp = "";
			}
		}
		else {
			temp += equ[i];
			if (i == equ.length() - 1) {
				if (flag) answer -= stoi(temp);
				else answer += stoi(temp);
			}
		}

		if (equ[i] == '-') flag = true; // �ڸ��� �ٲ� ������ �� �ڵ忡�� ó�� -�� ������ �� answer -= stoi(temp)�� �Ǳ� ���� 
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> equation;
	cout << sub2(equation);
	
	return 0;
}

// ���⿡�� ������ �� stoi�� ���ڰ� �ƴ� �ٸ� ���ڰ� ������ ������ �߻��Ѵ�.
// ���� �𸣰� +�� stoi�� �־��µ� ����ó���� �ȵƴٴ� ������ �߰��� �� �־���.