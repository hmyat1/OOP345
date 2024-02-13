//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca
{
    class Toy
    {
    private:
        int order_id{};
        std::string toy_name{};
        int toy_count{};
        double toy_price{};

    public:
        Toy();
        ~Toy() = default;
        void update(int numItems);
        Toy(const std::string &toy);
        friend std::ostream &operator<<(std::ostream &print, const Toy &toy) // << OVERLOADING
        {
            double subtotal = (toy.toy_price * toy.toy_count);
            double sales_tax = (13 * subtotal) / 100;
            double total = (subtotal + sales_tax);
            print << "Toy";
            print << std::setw(8) << toy.order_id << ":";
            print << std::setw(18) << std::right << toy.toy_name;
            print << std::setw(3) << std::right << toy.toy_count;
            print << " items";
            print << std::setw(8) << std::right << toy.toy_price;
            print << "/item  subtotal:";
            print << std::setw(7) << std::right << subtotal;
            print << " tax:";
            print << std::setw(6) << std::right << std::fixed << std::setprecision(2) << sales_tax;
            print << " total:";
            print << std::setw(7) << std::right << std::fixed << std::setprecision(2) << total << '\n';

            return print;
        }
    };
}

#endif