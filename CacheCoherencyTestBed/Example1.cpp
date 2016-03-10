#include "Timer.h"

#include <iostream>
#include <string>

template<size_t C>
struct Entity 
{
	char value;
	char padding[C-1];
};


template<int C>
static void LoopEntity()
{
	const size_t numEntities = 1024 * 1024;
    Entity<C>* entities = new Entity<C>[numEntities];

    {
        Timer t(std::to_string(sizeof(Entity<C>)) + ",", false);
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < numEntities; j++)
            {
                entities[j].value *= 3;
            }
            t.Lap();
        }
    }

	delete entities;
}


template<int C>
static void LoopDecr()
{
	LoopDecr<C-1>();
	LoopEntity<C>();
}


template<>
static void LoopDecr<2>()
{
	LoopEntity<2>();
}


void Example1()
{
    //LoopEntity<2>();  // Entities have size 2
    //LoopEntity<32>(); // Entities have size 64

    std::cout << "Count,Time(ms)" << std::endl;
    const int TotalSize = 128;
    LoopDecr<TotalSize>();
}
