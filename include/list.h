#include <iostream>

template<typename T>
class List {

private:

	struct Node {
		Node* next;
		T value;

		Node(T value_, Node* next_ = nullptr) : value(value_), next(next_) {}
	};

	int size = 0;
	Node* first = nullptr;

public:

	class Iterator {

	private:

		Node* ptr = nullptr;

	public:

		Iterator(Node* p): ptr(p) {}

		Node& operator*() const { return *ptr->value; }
		Node* operator->() const { return ptr->value; }

		Iterator& operator++() {
			ptr = ptr->next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator tmp = *this;
			ptr = ptr->next;
			return tmp;
		}

		bool operator==(const Iterator& iterator) const { return this->ptr == iterator.ptr; }
		bool operator!=(const Iterator& iterator) const { return this->ptr != iterator.ptr; }
	};

	Iterator begin() const { return Iterator(first); }
	Iterator end() const { return Iterator(nullptr); }

	List(){}
	~List(){}
};