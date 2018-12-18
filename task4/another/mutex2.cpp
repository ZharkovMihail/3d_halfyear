#include <cassert>
#include<thread>
#include<iostream>
#include<mutex>
using namespace std;
mutex m;

void foo(int &x) {
	for (int i = 0; i < 1000000; ++i) {
		m.lock();
		x += i;
		m.unlock();
	}
}

void bar(int &x) {
	for (int i = 0; i < 1000000; ++i) {
		m.lock();
		x -= i;
		m.unlock();
	}
}

int main() {
	int x = 0;
	std::thread th1([&x]() {foo(x); });
	std::thread th2([&x]() {bar(x); });
	std::thread th3([&x]() {foo(x); });
	std::thread th4([&x]() {bar(x); });

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	cout << x << endl;
	assert(x == 0);

	cout << "Done.\n";
	system("pause");
}
