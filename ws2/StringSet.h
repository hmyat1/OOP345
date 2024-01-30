//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.1.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>
#include <string>

namespace seneca {
	class StringSet {
		std::string* array = nullptr;
		size_t totalString = 0;
	public:
		StringSet();
		~StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);
		StringSet(StringSet&&)noexcept;
		StringSet& operator=(StringSet&&)noexcept;
		size_t size();
		std::string operator[](size_t);
	};
}

#endif 