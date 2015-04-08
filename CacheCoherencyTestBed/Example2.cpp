#include "Timer.h"


static const int steps = 256 * 1024 * 1024;
static int* gArr = new int[2];

// Increment the same element twice in each iteration
static void SameElement()
{
	Timer t("Loop Same");
	for (int i = 0; i<steps; i++) { gArr[0]++; gArr[0]++; }
}

// Increment different elements in each iteration
static void DifferentElements()
{
	Timer t("Loop Different");
	for (int i = 0; i<steps; i++) { gArr[0]++; gArr[1]++; }
}



void Example2()
{
	SameElement();
	DifferentElements();
}