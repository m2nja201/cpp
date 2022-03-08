// ī�� �����ϱ�(1715)
// 3.6~3.7
// ����

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> minheap; // greater => ��������, less<int> => �������� ******** �� ���� ���� pq �Լ� ã�ٰ� �߰�
	
	// �������� ���� ���� : �迭�� �޾Ƽ� ������������ ����, ������� ���ϱ�
	// �������� �� : �ƹ��� ���� �ͺ��� ���߾ ���� ���� �� ���� ������ Ŭ �� ���� ex) 20 30 40 70=> 50 > 40 70 �����Ӵϳ�!

	// �������� ���� : �ִ´�� ������������ �ٲ㼭 ���� ���� �ͳ��� ���� �� �ֵ��� �Ѵ�!
	// �������� : �˾Ƽ� �������� ������ ��.

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		minheap.push(num);
	}

	int answer = 0;
	int min1 = 0; int min2 = 0;
	while (minheap.size()!= 1) {
		min1 = minheap.top(); minheap.pop(); // ���� ���� �� �� �� ������
		min2 = minheap.top(); minheap.pop();
		minheap.push(min1 + min2); // �ּ����� �־��ֱ� (�˾Ƽ� ����)
		answer += (min1 + min2); 
	}
	
	cout << answer;
	return 0;
}