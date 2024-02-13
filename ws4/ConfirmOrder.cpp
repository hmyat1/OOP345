//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "ConfirmOrder.h"

namespace seneca
{
    ConfirmOrder::ConfirmOrder() = default;

    std::ostream &operator<<(std::ostream &out, ConfirmOrder &confirmOrder)
    {
        out << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
            << std::setfill(' ');
        out << "Confirmations to Send" << '\n';
        out << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
            << std::setfill(' ');
        if (confirmOrder.count == 0)
        {
            out << "There are no confirmations to send!" << '\n';
        }

        for (int i = 0; i < confirmOrder.count; ++i)
        {
            out << *(confirmOrder.array_toy[i]); // << OVERLOADING
        }

        out << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
            << std::setfill(' ');
        return out;
    }

    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {
        for (int i = 0; i < count; ++i)
        {
            if (array_toy[i] == &toy)
            {
                return *this;
            }
        }

        //TEMP ARRAY
        const Toy **temp = new const Toy *[count + 1];
        temp[count] = &toy;

        for (int i = 0; i < count; ++i)
        {
            temp[i] = array_toy[i];
        }

        delete[] array_toy;

        array_toy = new const Toy *[count + 1];

        for (int i = 0; i <= count; ++i)
        {
            array_toy[i] = temp[i];
        }

        delete[] temp;

        ++count;
        return *this;
    }

    ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
    {
        int j = count;
        for (int i = 0; i < count; ++i)
        {
            if (array_toy[i] == &toy)
            {
                array_toy[i] = nullptr;
                for (; i < count - 1; ++i)
                {
                    array_toy[i] = array_toy[i + 1];
                }
                count--;
                break;
            }
        }

        if (j != count)
        {
            const Toy **temp = new const Toy *[count]; 
            for (int i = 0; i < count; ++i)
            {
                temp[i] = array_toy[i];
            }
            for (int i = 0; i < count; ++i)
            {
                array_toy[i] = nullptr;
            }
            delete[] array_toy;
            array_toy = new const Toy *[count];
            for (int i = 0; i < count; ++i)
            {
                array_toy[i] = temp[i];
            }
            delete[] temp;
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder &confirmOrder)
    {
        if (this != &confirmOrder) 
        {
            this->count = confirmOrder.count;
            this->array_toy = new const Toy *[this->count];
            for (int i = 0; i < this->count; ++i)
            {
                this->array_toy[i] = confirmOrder.array_toy[i];
            }
        }
    }

    ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &assign_this)
    {
        if (this != &assign_this)
        {
            this->count = 0;
            this->count = assign_this.count;
            if (this->array_toy != nullptr) 
            {
                delete[] array_toy;
            }
            this->array_toy = new const Toy *[this->count];

            for (int i = 0; i < this->count; ++i)
            {
                this->array_toy[i] = assign_this.array_toy[i];
            }
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder &&confirmOrder)
    {
        if (this != &confirmOrder) 
        {
            this->count = 0;
            this->count = confirmOrder.count;
            this->array_toy = confirmOrder.array_toy;

            confirmOrder.count = 0;
            confirmOrder.array_toy = nullptr;
        }
    }

    ConfirmOrder::~ConfirmOrder()
    {
        if (array_toy != nullptr)
        {
            delete[] array_toy;
        }
    }
}
