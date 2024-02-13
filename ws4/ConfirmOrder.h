//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include <iostream>
#include <iomanip>
#include "Toy.h"

namespace seneca
{
    class ConfirmOrder
    {
    public:
        ConfirmOrder();
        friend std::ostream &operator<<(std::ostream &out, ConfirmOrder &confirmOrder);
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        ConfirmOrder(const ConfirmOrder &confirmOrder);
        ConfirmOrder &operator=(const ConfirmOrder &assign_this);
        ConfirmOrder(ConfirmOrder &&confirmOrder);
        ~ConfirmOrder();

    private:
        const seneca::Toy **array_toy = nullptr;
        int count{0};
    };
}

#endif
