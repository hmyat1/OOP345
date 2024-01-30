//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.1.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <iostream>
#include <chrono>
#include <cstring>

namespace seneca {

	const int maxNumOfEventObj = 10;

	class TimedEvents {
		int numOfRecords{ 0 };
		std::chrono::steady_clock::time_point sTime;
		std::chrono::steady_clock::time_point eTime;
		struct {
			std::string nameOfEvent;
			std::string timeUnits;
			std::chrono::steady_clock::duration durationOfEvent;
		}events[maxNumOfEventObj];

	public:
		TimedEvents();
		~TimedEvents();
		void addEvent(const char*);
		void startClock();
		void stopClock();
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}

#endif 