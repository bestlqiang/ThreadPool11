// ThreadPool11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <chrono>
#include <condition_variable>
#include "thread_pool.hpp"

using namespace std;

/*int g_sum = 0;

std::mutex g_mutex;
std::condition_variable g_cond;

void testfun()
{

printf("testfun() wait\n" );
std::unique_lock<std::mutex> g_lock(g_mutex);
g_cond.wait(g_lock);

printf("testfun exit\n");
}

void testfun2()
{

printf("testfun2 wait\n" );
std::unique_lock<std::mutex> g_lock(g_mutex);
g_cond.wait_for(g_lock, std::chrono::milliseconds(3500));

printf("testfun2 exit\n");
}


int main()
{
Thread t(testfun);
t.start();
Thread t2(testfun2);
t2.start();

printf("%d\n", t.getThreadId());

getchar();

printf("notify testfun\n");
g_cond.notify_one();

getchar();
}*/
/*
std::mutex g_mutex;

int main()
{
Condition cond(g_mutex);

cond.waitForSeconds(3.1658);

printf("main exit\n");

return 0;
}
*/
/*
int main()
{
{
ThreadPool threadPool;
threadPool.start();

getchar();
}

getchar();

return 0;
}

*/

/*
std::mutex g_mutex;
typedef lock_guard<mutex>  LockGuard_Mutex;

void priorityFunc()
{
	for (int i = 1; i < 4; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		LockGuard_Mutex lock(g_mutex);
		std::cout << "priorityFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] output" << std::endl;
	}

}

void testFunc()
{
	// loop to print character after a random period of time
	for (int i = 1; i < 4; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		LockGuard_Mutex lock(g_mutex);
		std::cout << "testFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] output" << std::endl;
	}
	
}



int main()
{
	sola::active_logger = std::unique_ptr<sola::logger>(new sola::logger(sola::logger::log_level::debug));

	sola::thread_pool thread_pool;

	for (int i = 0; i < 5; i++)
		thread_pool.add_task(testFunc);

	thread_pool.add_task(priorityFunc);

	getchar();
	return 0;
}
*/
#include <thread>

void  GetRet(int in,int & out)
{
	out = in * 2;
}

int main()
{
	int ret = 0;
	thread th(GetRet,5, ref(ret));
	th.join();
	cout << ret << endl;
	return 0;
}

