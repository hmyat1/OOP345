//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 2.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Pair.h"

namespace seneca
{
    template <typename T, int CAPACITY>
    class Collection
    {
    private:
        T _dummy_obj{}; 
    public:
        int _n_capacity = 0; 
        T _collection_arr[CAPACITY];
        int capacity_cpy = CAPACITY;

        int size()
        {
            return _n_capacity;
        }

        const void display()
        {
            std::cout << "----------------------\n";
            std::cout << "| Collection Content |\n";
            std::cout << "----------------------\n";
            for (int i = 0; i < _n_capacity; ++i)
            {
                std::cout << _collection_arr[i] << "\n"; 
            }
            std::cout << "----------------------\n";
        }

        virtual bool add(const T &item)
        {
            if (_n_capacity >= CAPACITY)
            {
                return false;
            }
            static int i = 0; 
            _collection_arr[i] = item;
            ++_n_capacity;
            ++i;
            return true;
        }

        virtual ~Collection() {}
        T operator[](int index)
        {
            if (index >= _n_capacity)
            {
                return _dummy_obj;
            }
            else
            {
                return _collection_arr[index];
            }
        }
    };

    template <> 
    class Collection<seneca::Pair, 100>
    {
    private:
        Pair _dummy_obj{"No Key", "No Value"}; 
    public:
        int _n_capacity = 0; 
        Pair _collection_arr[100];
        int size()
        {
            return _n_capacity;
        }
        const void display()
        {
            std::cout << "----------------------\n";
            std::cout << "| Collection Content |\n";
            std::cout << "----------------------\n";
            for (int i = 0; i < _n_capacity; ++i)
            {
                std::cout << _collection_arr[i] << "\n"; 
            }
            std::cout << "----------------------\n";
        }

        bool add(const Pair &item)
        {
            if (_n_capacity >= 100)
            {
                return false;
            }
            static int i = 0; 

            _collection_arr[i] = item;
            for (int x = 0; x < i; ++x)
            {
                if (x != i && (_collection_arr[i].getKey() == _collection_arr[x].getKey()))
                {
                    return false;
                }
            }
            ++_n_capacity;
            ++i;
            return true;
        }

        Pair operator[](int index)
        {
            if (index >= _n_capacity)
            {
                return _dummy_obj;
            }
            else
            {
                return _collection_arr[index];
            }
        }
    };
}

#endif