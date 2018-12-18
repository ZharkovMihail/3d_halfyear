#include <thread>
#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

template <typename T, class F>
class future {
	thread *t;
	T *data;
	future(const future&) = delete;
public:
	future() {
		F temp;
		data = new T();
		t = new thread(temp, data);
	}
	future(future &&other) : t(other.t), data(other.data) {}
	T &get() {
		t->join();
		return *data;
	}
	~future() {
		delete t;
		delete data;
	}
};
class IntFunc {
public:
	void operator()(int *d) {
		this_thread::sleep_for(chrono::seconds(5));
		*d = 15;
	}
};

typedef future<int, IntFunc> FuncFuture;
void foo(FuncFuture &&x) {
	cout<< x.get();
}

int main() {
	FuncFuture f;
	cout << "start" << endl;
	foo(move(f));
	system("pause");
	return 0;
}
