#include <Windows.h>

void Example1();
void Example2();
void Example3();

// This mostly lifted from
// http://igoro.com/archive/gallery-of-processor-cache-effects/

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

	return 0;

}