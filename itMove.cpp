#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main() {
	vector<string> vec = { "name1", "name2", "name3", "name2", "name3", "name4" };

	auto it = vec.begin();
	cout << "가장 최근 우승자: " << *it << endl;

	it += 3;
	cout << "3년 전 우승자: " << *it << endl;

	advance(it, -1);
	cout << "그 후 1년 뒤 우승자: " << *it << endl;
}