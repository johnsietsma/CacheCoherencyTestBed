#include "Timer.h"

#include <string>

static const int gCount = 64 * 1024 * 1024;
static int* gArr = new int[gCount];


// Templated purely so we get different functions generated that we can see in the profiler.
template<int C>
static void Loop( int incCount )
{
	// Loop through the array using incCount as the stride.
	Timer t("Loop " + std::to_string(incCount), incCount);
	for (int i = 0; i < gCount; i += incCount)
	{
		gArr[i] *= 3;
	}
}


void Example1()
{
	Loop<1>(1);  // Update every element
	Loop<16>(16); // Update every 16th element

	/*
	for (int i = 0; i < 12; i++)
	{
		Loop<1>(1<<i);
	}
	*/

}
