#include <mutex>
#include<iostream>
#include<thread>
using namespace std;

void Print(char c) {
	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 7; i++) {
			cout << c;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	thread t1(Print, 'B');
	thread t2(Print, 'N');
	t1.join();
	t2.join();
	system("pause");
	return 0;
}
