#include "Timer.h"

#include <string>

template<int C>
struct Entity 
{
	char value;
	char padding[C-1];
};


template<int C>
static void LoopEntity()
{
	const int numEntities = 1024 * 1024;
	Entity<C>* entities = new Entity<C>[numEntities];

	Timer t("Loop Entity " + std::to_string(C));
	for (int i = 0; i < numEntities; i++)
	{
		entities[i].value *= 3;
	}

	delete entities;
}


template<int C>
static void LoopHalf()
{
	LoopHalf <C/2>();
	LoopEntity<C>();
}


template<>
static void LoopHalf<2>()
{
	LoopEntity<2>();
}


void Example1()
{
	LoopEntity<2>();  // Entities have size 2
	LoopEntity<64>(); // Entities have size 16

	LoopHalf<1024>();
}
