#include <iostream>
using namespace std;
#include <queue>

priority_queue<int> maxheap;
int main() {

	int N=0;
	scanf("%d", N);
	int x=0;

	for (int i = 0; i < N; i++) {
		scanf("%d", x);
		if (x == 0) {
			if (maxheap.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", maxheap.top());
				maxheap.pop();
			}
		}
		else {
			maxheap.push(x);
		}
	}
	
	return 0;
}