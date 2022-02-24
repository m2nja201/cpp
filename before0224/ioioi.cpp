// 5525 IOIOI
// 참고 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ndb796&logNo=221240679247

#include <iostream>
#include <algorithm>

using namespace std;

int Pn(int n) { // Pn의 hash값을 return
	// P1 = IOI, P2 = IOIOI; & (ASCII) I=73, O=79
	int number = 0;
	long long power = 1;
	for (int i = 1; i <= (2 * n + 1); i++) {
		if (i % 2 != 0) {
			number = number + 73 * power;
		}
		else number = number + 79 * power;
		power *= 2;
	}
	return number;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	char s[10000];
	cin >> s;

	int cHash = Pn(N);
	int strsize = 2 * N + 1;

	int count = 0;
	long long pow = 1;

	for (int i = 0; i < M - strsize + 1; i++) {
		if (s[i] != 'O' && s[i] != 'I') break;
		if (s[i] == 'O') continue;
		int pHash = 0;

		for (int j = i; j < i + strsize; j++) {
			pHash = pHash + s[j] * pow;
			pow = pow * 2;
		}
		//cout << i << "번째 Hash : " << pHash << ",   비교 : " << cHash << endl;
		if (pHash == cHash) {
			count++;
		}
		pow = 1; 
	}

	cout << count;
	return 0;
}