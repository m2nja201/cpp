// 가장 긴 문자열
// 0222 update

// 접미사 배열에서 공통된 prefix를 공유할 때 그 개수를 LCP(Longest Common Prefix)에 저장

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
	
	while (left + 1 < right) { // 이분 탐색
		int mid = (left + right) / 2;
		long long pow = 1;
		bool flag = false;
		int hash = 0;
		vector<int> hashvec[mod];

		
		for (int i = 0; i + mid < L; i++) { // 문자열 길이만큼 반복
			if (i == 0) {
				for (int k = 0; k < mid; k++) {
					hash = modul(hash + str[mid - 1 - k] * pow);
					// 부분 문자열 해시값 찾기 (i==0이면 새로 만들기)
					if (k + 1 < mid) pow = modul(pow << 1); /// << 연산에 대해 생각해보기 (shift)
				}
			}
			else {
				hash = modul(2 * (hash - str[i - 1] * pow) + str[i + mid - 1]); // 한 char씩 빼주고 더해주기
			}

			if (!hashvec[hash].empty()) { // 같은 해쉬값이 있는 경우
				for (int p : hashvec[hash]) {
					bool b = true;
					for (int j = 0; j < mid; j++) { // 문자열이 같은지
						if (str[i + j] != str[p + j]) {
							b = false; // 같지 않으면
							break;
						}
					}
					if (b) { // 같으면
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