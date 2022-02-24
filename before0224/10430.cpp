//0220
//10430
#include <iostream>
using namespace std;

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	if (C == 0) return 0;
	int cal1 = (A + B) % C;
	int cal2 = ((A % C) + (B % C)) % C;
	int cal3 = (A * B) % C;
	int cal4 = ((A % C) * (B % C)) % C;

	cout << cal1 << "\n" << cal2 << "\n" << cal3 << "\n" << cal4;
}