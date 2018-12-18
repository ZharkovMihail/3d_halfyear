#include <mutex>
#include<iostream>
using namespace std;

template <typename T>
class Atomic {
	mutex m;
	T data;
public:
	Atomic(const T &other = T()) : data(other) {}
	T operator=(const T &other) {
		m.lock();
		data = other;
		m.unlock();
		return data;
	}
	operator T() {
		m.lock();
		T res(data);
		m.unlock();
		return res;
	}
};

int main() {
	Atomic <int> a(1);
	Atomic <int> b(a+2);
	cout << a + b;
	system("pause");
	return 0;
}
