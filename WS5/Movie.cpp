//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 27.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include <sstream>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace seneca {
	const string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const string& strMovie) {
		if (!strMovie.empty()) {
			stringstream line(strMovie);
			string temp{};
			getline(line, m_title, ',');
			m_title.erase(0, m_title.find_first_not_of(' '));
			m_title.erase(m_title.find_last_not_of(' ') + 1);

			getline(line, temp, ',');
			m_year = stoi(temp);

			getline(line, m_des, '\n');
			m_des.erase(0, m_des.find_first_not_of(' '));
			m_des.erase(m_des.find_last_not_of(' ') + 1);
		}
		else {
			*this = Movie();
		}
	}

	ostream& operator<<(ostream& os, const Movie& src) {
		os << setw(40) << right << src.m_title << " | ";
		os << setw(4) << src.m_year << " | ";
		os << left << src.m_des << endl;
		return os;
	}
}