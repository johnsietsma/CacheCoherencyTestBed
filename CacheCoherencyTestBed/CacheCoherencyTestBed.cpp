#include <Windows.h>

void Example1();
void Example2();
void Example3();
void Example4();

// This mostly lifted from
// http://igoro.com/archive/gallery-of-processor-cache-effects/
// https://medium.com/swlh/branch-prediction-everything-you-need-to-know-da13ce05787e

// Put this in the command-line to find out your cache sizes.
// wmic cpu get L2CacheSize, L3CacheSize

int main(int argc, char* argv[])
{

	// Cache line size
	//Example1();

	// Parallelism
	//Example2();

	// Invalidate cache line
	//Example3();

	// Branch prediction
	Example4();

	return 0;

}