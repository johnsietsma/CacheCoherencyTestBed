#pragma once

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

typedef std::chrono::high_resolution_clock timing_clock;

// A simple timer designed to be used a stack variable. Prints out the results in the destruction.
class Timer
{
public:
	Timer( std::string timerName, unsigned int timeFactor=0 ) :
		m_startTime(timing_clock::now()),
		m_timeFactor(timeFactor),
		m_timerName(timerName)
		{
	}

	~Timer()
	{
		auto endTime = timing_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_startTime);

		// Print the results
		std::cout
			<< std::left << std::setw(25)
			<< m_timerName + ": "
			<< std::right << std::setw(10)
			<< std::to_string(elapsed.count()) + "ms";
		if (m_timeFactor != 0) {
			std::cout << std::setw(10)
				<< std::to_string(m_timeFactor) + " = "
				<< std::setw(10)
				<< elapsed.count()*m_timeFactor;
		} 
		std::cout << std::endl;
	}

private:
	timing_clock::time_point m_startTime;
	unsigned int m_timeFactor; // A multiplier on our time measurement, used to give a standard time for various workloads.
	std::string m_timerName;
};