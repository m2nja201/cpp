// ���� �� ���ڿ�

#include <iostream>
#include <set>
#include <cmath>
#include <iterator>
#define MOD 123457
#define endl "\n"

using namespace std;

int hNum(string str, int index, int term) {
	// hash code return���ִ� �Լ�
	// modulation�� ���� ��..!
	// ã�� str, ���� �ε���, ����
	int sum = 0;
	int intPow = 0;
	//cout << "** start index : "<<index<<" - ";
	for (int i = index; i < index + term; i++) {
		sum += str[i] * (int)pow(29, term - intPow - 1);
		intPow++;
		//cout << str[i];
	}
	//cout << " - " << sum << " **" << endl;
	sum = sum % MOD;
	return sum;
}

void print(set<int> hh) {
	for (auto iter = hh.begin(); iter != hh.end(); iter++) {
		cout <<"set : "<< * iter << "  ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int L;
	
	cin >> L >> str;
	int here = 0;
	int len = 1;
	set<int> hashNum;
	bool flag = false;
	// pair second�� boolean return
	if (L == 0 || L == 1) {
		cout << 0;
		return 0;
	}
	
	while (!flag) {
		flag = true;
		for (int j = 0; j < L-len+1; j++) {
			//cout << "1�ܰ�" << endl;
			int sumHash = hNum(str, j, len);
			flag = hashNum.insert(sumHash).second;
			//cout << "2�ܰ�" << endl;
			if (!flag) { // �ݺ��� �� �ִ�
				len++;
				//print(hashNum);
				hashNum.clear();
				if (len == L) {
					cout << len - 1;
					flag = true;
					break;
				}
				break;
			}

		}
		if(flag) { // ���� ������ 
			cout << len - 1;
			flag = true;
			break;
		}
		
	}
	return 0;
}