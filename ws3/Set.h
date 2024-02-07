//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 2.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"
#include <cmath>

namespace seneca
{
    template <typename T>
    class Set : public Collection<T, 100>
    {
    public:
        Set() = default;

        bool add(const T &item)
        {
            
            if (this->_n_capacity >= 100)
            {
                return false;
            }
            static int i = 0; 
            for (int x = 0; x < i; ++x)
            {
                if (this->_collection_arr[x] == item)
                {
                    return false;
                }
            }
            this->_collection_arr[i] = item;
            ++this->_n_capacity;
            ++i;
            return true;
        }

        ~Set(){};
    };

    template <>
    class Set<double> : public Collection<double, 100>
    {
    public:
        bool add(const double &item)
        {
            if (this->_n_capacity >= this->capacity_cpy)
            {
                return false;
            }
            static int i = 0; 

            for (int i = 0; i < this->_n_capacity; ++i)
            {
                if (std::fabs(this->_collection_arr[i] - item) <= 0.01)
                {
                    return false;
                }
            }
            this->_collection_arr[i] = item;

            ++this->_n_capacity;
            ++i;
            return true;
        }
    };
}

#endif