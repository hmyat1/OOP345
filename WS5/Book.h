//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <string>
using namespace std;
namespace seneca {
	class Book {
		string b_author{};
		string b_title{};
		string b_country{};
		size_t b_year{};
		double b_price{};
		string b_des{};
	public:
		Book() = default;
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		friend ostream& operator<<(ostream& os, Book& src);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(b_des);
		}
	};
}
#endif