// ����� �賶
// 0221
// fail

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K; // ��ǰ�� ��, ������ ����
	vector<pair<int, int> > things;

	cin >> N >> K;
	things.reserve(N);

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		things.push_back({ V, W }); // ����ġ�� �켱����
	}

	sort(things.begin(), things.end());
	
	int weight = 0, value = 0;
	int index = 0;
	while (weight <= K) {
		weight += things[index].second;
		if (weight > K) {
			if (index == N - 1) break;
			weight -= things[index].second;
			index++;
		}
		else {
			value += things[index].first;
			index++;
		}
		cout << index<<"  "<<value << endl;
	}

	cout << "=========" << endl;
	cout << value;

	return 0;

}