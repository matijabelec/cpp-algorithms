//
// @author: Matija
// @mail: matijabelec1@gmail.com
// @date: 2015, dec 27
// 
// g++ thread_hello.cpp -o thread_hello.out -pthread -std=c++11
//
#include <iostream>
#include <thread>
#include <unistd.h>
#include <signal.h>
using namespace std;

void say_hello() {
	cout << "thread started" << endl;
	
	while(1) {
		cout << "hello from thread" << endl;
		sleep(1);
	}
}

void sig_int_func(int) {
	cout << "stopping thread..." << endl;
    exit(0);
}

int main() {
	sigset(SIGINT, sig_int_func);
	
	thread thr(say_hello);
	thr.join();
	
	return 0;
}

