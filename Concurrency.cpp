///============================================================================
// Name        : Concurrency.cpp
// Author      : Grant Brosovich
// Version     : 1
// Copyright   : Some kind of Copyright
// Description : A simple counter with multi-threading
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;

std::mutex consoleMutex;

void countUp(int limit) {
		auto startTime = high_resolution_clock::now();

		for (int i = 1; i <= limit; ++i)
		{
			lock_guard<mutex> guard(consoleMutex);
			cout << "Counting Up: " << i << endl;
			this_thread::sleep_for(milliseconds(100));
		}
		auto endTime = high_resolution_clock::now();
		duration<double> elapsed = endTime - startTime;

		lock_guard<mutex> guard(consoleMutex);
		cout << "Thread 1 (Count Up) completed in " << elapsed.count() << " seconds.\n";
		}

void countDown(int start) {
	auto startTime = high_resolution_clock::now();

	for (int i = start; i >= 0; --i) {
		lock_guard<mutex> guard(consoleMutex);
		cout << "Counting Down: " << i << endl;
		this_thread::sleep_for(milliseconds(100));
	}

	auto endTime = high_resolution_clock::now();
	duration<double> elapsed = endTime - startTime;
	lock_guard<mutex> guard(consoleMutex);
	cout << "Thread 2 (COunt Down) completed in " << elapsed.count() << " seconds.\n";
	}
int main() {
	cout << "Starting concurrent counting exercise...\n";
	thread t1(countUp, 20);
	t1.join();
	thread t2(countDown, 20);
	t2.join();

	cout << "Both threads have finished execution.\n";
	return 0;
}

