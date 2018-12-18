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
void foo(Atomic<int> &x) {
	for (int i = 0; i < 10000; ++i) {
		x =x+ i;
	}
}

void bar(Atomic<int> &x) {
	for (int i = 0; i < 10000; ++i) {
		x =x- i;
	}
}


int main() {
	Atomic <int> a(1);
	Atomic <int> b(a + 2);
	cout << a + b;
	Atomic <int> x(1);
	std::thread th1([&x]() {foo(x); });
	std::thread th2([&x]() {bar(x); });

	th1.join();
	th2.join();

	cout << x << endl;
	system("pause");
	return 0;
}
