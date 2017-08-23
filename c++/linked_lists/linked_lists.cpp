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
			this->_size++;
		}
	}

	ll(const ll& other)
	{
		entry* tmp = other->_front;
		while (tmp) {
			
			

			tmp = tmp->p;
		}
	}

	void print() {
		entry* tmp = _front;
		while (tmp) {
			std::cout << tmp->value << " ";
			tmp = tmp->p;
		}
		std::cout << std::endl;
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

		this->_size++;
		assert(_back->p == NULL);
	}

	void push_front(T v) {
		if (_front == NULL) {
			_front = new(entry);
			_front->p = NULL;
			_front->value = v;
			_back = _front;

		} else {
			entry* tmp = new(entry);
			tmp->p = _front;
			tmp->value = v;
			_front = tmp;
		}

		this->_size++;
		assert(_back->p == NULL);
	}

	int size() {
		return _size;
	}

	T& operator[] (unsigned x) {
		assert(x <= this->_size);

		entry* tmp = _front;
		unsigned idx = 0;
		while (tmp) {
			if (idx == x)
				return tmp->value;
			idx++;
			tmp = tmp->p;
		}
	}

	~ll() {
		entry* tmp = _front;
		while (tmp) {
			entry* tmp2 = tmp->p;
			delete tmp;
			tmp = tmp2;
		}
	}

	ll<T>& operator= (const ll<T>& other)
	{
		return *this;
	}
};

int main() {
	ll<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_front(4);
	mylist.push_front(5);
	mylist.push_front(6);
	mylist.print();

	assert(mylist[2] == 4);
	assert(mylist.size() == 6);
}