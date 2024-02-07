//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 2.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <iomanip>

namespace seneca
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string &getKey() { return m_key; }
        const std::string &getValue() { return m_value; }
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};

        Pair(); 

        friend std::ostream &operator<<(std::ostream &out, const Pair &pair)
        {
            int colwidth{20};
            out << std::setw(colwidth) << std::right << pair.m_key << ": ";
            out << pair.m_value;

            return out;
        }

        friend bool operator==(const Pair &lhs, const Pair &rhs)
        {
            if (lhs.m_key == rhs.m_key)
            {
                return true;
            }

            return false;
        }
    };
}

#endif