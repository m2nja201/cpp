#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main() {
	vector<string> vec = { "name1", "name2", "name3", "name2", "name3", "name4" };

	auto it = vec.begin();
	cout << "���� �ֱ� �����: " << *it << endl;

	it += 3;
	cout << "3�� �� �����: " << *it << endl;

	advance(it, -1);
	cout << "�� �� 1�� �� �����: " << *it << endl;
}