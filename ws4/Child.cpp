//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "Child.h"

seneca::Child::Child(std::string name, int age, const Toy *toys[], size_t count)
{
    this->name = name;
    this->age = age;
    this->count = count;

    toy_array = new seneca::Toy *[count]; 
    for (size_t i = 0; i < count; ++i)  
    {
        toy_array[i] = nullptr;
    }

    for (size_t i = 0; i < count; ++i)
    {
        toy_array[i] = new seneca::Toy(*toys[i]); 
        ++toy_counter;
    }
}

seneca::Child::Child(const Child &child)
{
    this->name = child.name;
    this->age = child.age;
    this->count = child.count;
    this->toy_counter = child.toy_counter;
    this->~Child();
    this->toy_array = new seneca::Toy *[this->count]; 
    for (int i = 0; i < this->count; ++i)
    {
        toy_array[i] = nullptr;
    }

    for (int i = 0; i < this->count; ++i)
    {
        this->toy_array[i] = new seneca::Toy(*child.toy_array[i]); 
    }
}

seneca::Child::Child(Child &&child)
{
    this->name = "";
    this->age = 0;
    this->count = 0;
    this->toy_counter = 0;

    this->name = child.name;
    this->age = child.age;
    this->count = child.count;
    this->toy_counter = child.toy_counter;

    this->~Child();
    this->toy_array = child.toy_array;
    child.toy_array = nullptr;

    child.name = "";
    child.age = 0;
    child.count = 0;
    child.toy_counter = 0;
}

seneca::Child::~Child()
{
    if (toy_array != nullptr)
    {
        for (int i = 0; i < count; ++i)
        {
            delete toy_array[i];
            toy_array[i] = nullptr;
        }
        delete[] toy_array;
        toy_array = nullptr;
    }
}