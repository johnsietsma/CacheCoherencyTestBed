#include "Timer.h"

#include <algorithm>
#include <random>


static const int count = 256 * 1024;
static int* gArr = new int[count];

void randomise()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 256);

	for (int c = 0; c < count; ++c)
		gArr[c] = distribution(generator);
}

int sum()
{
	int sum = 0;
	for (int i = 0; i < 1024; ++i) {
		// Primary loop
		for (int c = 0; c < count; ++c) {
			if (gArr[c] >= 128)
				sum += gArr[c];
		}
	}
	return sum;
}

// Conditionally sum a sorted array
static void Sorted()
{
	randomise();
	std::sort(gArr, gArr + count);

	{
		Timer t("Sorted");
		sum();
	}
}

// Conditionally sum an unsorted array
static void Unsorted()
{
	randomise();

	{
		Timer t("Unsorted");
		sum();
	}
}



void Example4()
{
	Sorted();
	Unsorted();
}