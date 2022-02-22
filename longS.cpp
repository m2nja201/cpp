// ���� �� ���ڿ�
// 0222 update

// ���̻� �迭���� ����� prefix�� ������ �� �� ������ LCP(Longest Common Prefix)�� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 10003;

int L;

int modul(long long n) {
	if (n >= 0) return n % mod;
	else return ((-n / mod + 1) * mod + n) % mod;
}

int main() {
	cin >> L;
	char str[200001];
	int left = 0; int right = L;

	for (int i = 0; i < L; i++) {
		cin >> str[i];
	}
	
	while (left + 1 < right) { // �̺� Ž��
		int mid = (left + right) / 2;
		long long pow = 1;
		bool flag = false;
		int hash = 0;
		vector<int> hashvec[mod];

		
		for (int i = 0; i + mid < L; i++) { // ���ڿ� ���̸�ŭ �ݺ�
			if (i == 0) {
				for (int k = 0; k < mid; k++) {
					hash = modul(hash + str[mid - 1 - k] * pow);
					// �κ� ���ڿ� �ؽð� ã�� (i==0�̸� ���� �����)
					if (k + 1 < mid) pow = modul(pow << 1); /// << ���꿡 ���� �����غ��� (shift)
				}
			}
			else {
				hash = modul(2 * (hash - str[i - 1] * pow) + str[i + mid - 1]); // �� char�� ���ְ� �����ֱ�
			}

			if (!hashvec[hash].empty()) { // ���� �ؽ����� �ִ� ���
				for (int p : hashvec[hash]) {
					bool b = true;
					for (int j = 0; j < mid; j++) { // ���ڿ��� ������
						if (str[i + j] != str[p + j]) {
							b = false; // ���� ������
							break;
						}
					}
					if (b) { // ������
						flag = true;
						break;
					}
				}
				
			}
			if (flag) break;
			else hashvec[hash].push_back(i);
		}
		if (flag) left = mid;
		else right = mid;
	}

	cout << left;
	//for (int j = 0; j < L; j++) {
	//	cout << str[j]; // print
	//}
	return 0;
}