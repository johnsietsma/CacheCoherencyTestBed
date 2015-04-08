#include "Timer.h"
#include <thread>

static int* gCounter = new int[1024];


// Update the same counter lots of times
static void UpdateCounter(int position)
{
	for (int j = 0; j < 100000000; j++)
	{
		gCounter[position] = gCounter[position] + 3;
	}
}

// Multithread the update
static void UpdateThreaded( int index1, int index2, int index3, int index4)
{
	Timer t("Threaded");
	auto thread1 = std::thread(UpdateCounter, index1);
	auto thread2 = std::thread(UpdateCounter, index2);
	auto thread3 = std::thread(UpdateCounter, index3);
	auto thread4 = std::thread(UpdateCounter, index4);

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
}

void Example3()
{
	UpdateThreaded(0, 1, 2, 3);
	UpdateThreaded(0, 16, 32, 48);
}
