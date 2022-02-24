//0221
// success

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p; // 케이스, 선수 수
	cin >> n;

	while (n--) {
		cin >> p;
		int val = 0, preval = 0;
		string name = "", prename = "";
		while (p--) {
			cin >> val >> name;
			if (val > preval) {
				prename = name;
				preval = val;
			}
		}
		cout << prename;
	}
	return 0;
}