//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <string>
using namespace std;
const int MAX = 6;
namespace seneca {
	class SpellChecker {
		string m_badWords[MAX];
		string m_goodWords[MAX];
		int CNT[MAX]{ 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out);
	};
}
#endif