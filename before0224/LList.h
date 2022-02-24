#pragma once
template <typename T>
struct Node {
	T data;
	struct Node<T> *next = nullptr;
};

template <typename T>
class SLlist {
public :
	SLlist() : head(nullptr), tail(nullptr) {}
	~SLlist() {}
	void push(T val);
private:
	Node<T>* head;
	Node<T>* tail;
	int size = 0;
};

template <typename T>
void push(T val) {
	Node<T>* node = new Node<T>;
	node -> value = val;
	node->next = nullptr;
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = tail->next;
	}
	tail->next = head;
}

template <typename T>
T remove(T val) {
	Node<T>* ptr = head;
	Node<T>* temp = ptr;

}