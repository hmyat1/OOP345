//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"

namespace seneca {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string temp;
			size_t i = 0;
			while (file && i < MAX) {
				getline(file, m_badWords[i], ' ');
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
			}
			file.close();
		}
	}

	void SpellChecker::operator()(string& text) {
		for (int i = 0; i < MAX; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				++CNT[i];
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) {
		cout << "Spellchecker Statistics" << endl;
		for (int i = 0; i < MAX; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << CNT[i] << " replacements" << endl;
		}
	}
}