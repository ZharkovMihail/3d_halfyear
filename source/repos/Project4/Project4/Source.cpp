#include <iostream>
#include <thread>
#include <ctime>

using namespace std;
int sum(int arr[]) {
	int s = 0;
	for (int i = 0; i <= 4; i++) {
		s += arr[i];
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	return s;
}

int main() {
	int a1[5],a2[5],a3[5],a4[5];
	for (int i = 0; i < 5; i++) {
		a1[i] = 1 + i;
		a2[i] = 2 + i;
		a3[i] = 3 + i;
		a4[i] = 4 + i;
	}
	int res1,res2,res3,res4;
	srand(time(0));
	thread t1([&res1, &a1]() {res1 = sum(a1); });
	thread t2([&res2, &a2]() {res2 = sum(a2); });
	thread t3([&res3, &a3]() {res3 = sum(a3); });
	thread t4([&res4, &a4]() {res4 = sum(a4); });
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	int Res = res1 + res2 + res3 + res4;
	cout << Res<<endl;
	auto t = clock() / 1000.0;
	cout << "runtime1 = " << t<< endl;
	
	Res = sum(a1) + sum(a2) + sum(a3) + sum(a4);
	cout << Res << endl;
	cout << "runtime1 = " << clock() / 1000.0 -t<< endl;

	system("pause");
	return 0;
}