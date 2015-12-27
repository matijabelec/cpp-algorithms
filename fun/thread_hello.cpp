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

int running;

void say_hello() {
	cout << "thread started" << endl;
	
	while(running) {
		cout << "hello from thread" << endl;
		sleep(1);
	}
	
	cout << "thread stopped" << endl;
}

void sig_int_func(int) {
	cout << "stopping thread..." << endl;
	running = 0;
}

int main() {
	running = 1;
	
	sigset(SIGINT, sig_int_func);
	
	thread thr(say_hello);
	thr.join();
	
	return 0;
}

