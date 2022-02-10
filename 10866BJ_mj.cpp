// 10866
// deque

#include <iostream>
#include <algorithm>
#include <String>
using namespace std;


class Deque {
public:
	Deque(const int size);
	~Deque() { delete[] deque; }

	void push_front(int elem);
	void push_back(int elem);
	int pop_front();
	int pop_back();
	int size() const;
	bool empty() const;
	int front();
	int back();
	void sizeException() {
		cout << "size error / quit" << endl;
		exit(EXIT_FAILURE);
	}

private:
	int deque[100];
	int d_front;
	int rear;
	int capacity;
	int max = 100;
	int temp;
};

Deque::Deque(const int d_size) {
	capacity = d_size;
	d_front = 0;
	rear = 1;
	temp = 0;
	fill_n(deque, 100, 0);
}

void Deque::push_front(int elem) {
	if (deque[(d_front - 1 + max) % max] == 0) {
		d_front = (d_front - 1 + max) % max;
		deque[d_front] = elem;
		capacity++;
	}
	else {
		sizeException();
	}
}

void Deque::push_back(int elem) {
	if (deque[rear] == 0) {
		rear = (rear + 1) % max;
		deque[rear - 1] = elem;
		capacity++;
	}
	else {
		sizeException();
	}
}

int Deque::pop_front() {
	if (empty()) {
		sizeException();
	}
	else {
		if (deque[d_front] = 0) {
			return (-1);
		}
		else {
			temp = deque[d_front];
			deque[d_front] = 0;
			return temp;
		}
	}
}

int Deque::pop_back() {
	if (empty()) {
		sizeException();
	}
	else {
		if (deque[rear - 1] == 0) {
			return (-1);
		}
		else {
			temp = deque[(rear - 1 + max) % max];
			deque[(rear - 1 + max) % max] = 0;
			return temp;
		}
	}
}

int Deque::size() const {
	cout << capacity << endl;
	return capacity;
}
bool Deque::empty() const {
	if (capacity == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int Deque::front() {
	if (deque[d_front] = 0) {
		return (-1);
	}
	else {
		cout << deque[d_front] << endl;
		return deque[d_front];
	}
}
int Deque::back() {
	if (deque[rear - 1] == 0) {
		return (-1);
	}
	else {
		cout << deque[(rear - 1 + max) % max] << endl;
		return deque[(rear - 1 + max) % max];
	}
}

//void Deque::search(string ord, int ele) {
//	if (ord == "push_back") push_back(ele);
//	else if (ord == "push_front") push_front(ele);
//	else if (ord == "pop_front") pop_front();
//	else if (ord == "pop_back") pop_back();
//	else if (ord == "size") size();
//	else if (ord == "empty") empty();
//	else if (ord == "front") front();
//	else if (ord == "back") back();
//	else {
//		cout << "error : quit" << endl;
//		exit(EXIT_FAILURE);
//	}
//}

int main() {
	int N; // ¸í·É ¼ö
	cin >> N;
	Deque order(N);

	string orderM;
	int element = 0;

	for (int i = 0; i < N; i++) {
		cin >> orderM >> element;
		if (orderM == "push_back") order.push_back(element);
		else if (orderM == "push_front") order.push_front(element);
		else if (orderM == "pop_front") cout << order.pop_front() << endl;
		else if (orderM == "pop_back") cout << order.pop_back() << endl;
		else if (orderM == "size") cout << order.size() << endl;
		else if (orderM == "empty") cout << order.empty() << endl;
		else if (orderM == "front") cout << order.front() << endl;
		else if (orderM == "back") cout << order.back() << endl;
		else {
			cout << "error : quit" << endl;
			exit(EXIT_FAILURE);
		}
	}
}