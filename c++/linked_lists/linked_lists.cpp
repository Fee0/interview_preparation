#include <iostream>
#include <string>
#include <assert.h>

template <class T>
class ll {

private:
	struct entry
	{
		entry* p;
		T value;
	};

	entry* _front;
	entry* _back;
	int _size;

public:

	ll(): _size(0), _front(NULL), _back(NULL) {
	}

	ll(int size): _size(size) {
		entry* tmp = _front;

		for (int idx = 0; idx < size; ++idx) {
			tmp = new(entry);
			tmp->p = NULL;
			tmp->value = 123;
			_back = tmp;
			tmp = tmp->p;
		}
	}

	void print() {
		entry* tmp = _front;
		while (tmp) {
			std::cout << tmp->value << std::endl;
			tmp = tmp->p;
		}
	}

	void push_back(T v) {
		if (_back == NULL) {
			_front = new(entry);
			_front->p = NULL;
			_front->value = v;
			_back = _front;

		} else {
			_back->p = new(entry);
			_back->p->p = NULL;
			_back->p->value = v;
			_back = _back->p;

		}

		assert(_back->p == NULL);
	}
};

int main() {
	ll<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.print();
	std::cout << "hello" << std::endl;
}