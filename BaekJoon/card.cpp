//  ī������ ���� : (1) ī�� 1���� ����, (2) ī�� 2���� ���� ... (N) ī�� N���� ����
// N���� �����Ϸ��� �Ѵ�. ī�� i�� ���Ե� ī������ ������ Pi

#include <iostream>
#include <vector>
using namespace std;

/*
void function(const vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
} */

int main() {
	int N; // �α԰� �����Ϸ��� �ϴ� ī�� ����
	// cout << "ī�� ���� N : ";
	cin >> N;

	int real = N + 1; // index 1���� ����ҷ���!
	vector<int> Pi(real);
	Pi[0] = 0;

	// cout << "Pi~PN�� ������� �Է� : ";
	for (int i = 1; i < Pi.size(); i++) {
		cin >> Pi[i];
	}

	vector<int> maxPi(real);
	
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= i; k++) {
			if (i >= k) {
				int temp = i - k;
				maxPi[i] = max(maxPi[i], maxPi[temp] + Pi[k]); 
				// cout << "i, k = " << i << ", " << k << " => " << maxPi[i] << endl;
			}
			
		}
	}

	cout << maxPi[N] << endl;
	return 0;
}