//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include "Toy.h"

namespace seneca
{
    class Child
    {
    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);

        // << OVERLOADING
        friend std::ostream &operator<<(std::ostream &output, const Child &child)
        {
            static int CALL_CNT = 1;
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            output << "Child " << CALL_CNT << ": " << child.name << " " << child.age << " years old:\n";
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            if (child.count == 0)
            {
                std::cout << "This child has no toys!" << '\n';
            }
            for (int i = 0; i < child.count; ++i)
            {
                std::cout << *child.toy_array[i]; 
            }
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            ++CALL_CNT;
            return output;
        }

        size_t size() const
        {
            return toy_counter;
        }

        Child(const Child &child);

        Child &operator=(const Child &child)
        {
            if (this != &child)
            {
                this->~Child(); 
                this->name = child.name;
                this->age = child.age;
                this->count = child.count;
                this->toy_counter = child.toy_counter;

                this->toy_array = new seneca::Toy *[this->count];

                for (int i = 0; i < this->count; ++i)
                {
                    this->toy_array[i] = new seneca::Toy(*child.toy_array[i]); 
                }
            }
            return *this;
        }

        Child(Child &&child);

        Child &operator=(Child &&child)
        {
            if (this != &child) 
            {
                this->name = child.name;
                this->age = child.age;
                this->count = child.count;
                this->toy_counter = child.toy_counter;

                if (this->toy_array != nullptr)
                {
                    for (int i = 0; i < this->count; ++i)
                    {
                        this->toy_array[i] = nullptr;
                    }
                    delete[] this->toy_array;
                    this->toy_array = nullptr;
                }

                this->toy_array = child.toy_array;
                child.toy_array = nullptr;

                child.name = "";
                child.age = 0;
                child.count = 0;
                child.toy_counter = 0;
            }
            return *this;
        }

        ~Child();

        Child() = default;

    private:
        seneca::Toy **toy_array = nullptr;
        std::string name{};
        int age{};
        int count{};
        int toy_counter = 0;
    };
}

#endif