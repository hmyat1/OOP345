//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <string>
#include "SpellChecker.h"
using namespace std;
namespace seneca {
	class Movie {
		string m_title{};
		size_t m_year{};
		string m_des{};
	public:
		Movie() = default;
		const string& title() const;
		Movie(const string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_des);
		}
		friend ostream& operator<<(ostream& os, const Movie& src);
	};
}
#endif