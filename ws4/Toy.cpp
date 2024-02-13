//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 10.2.24

// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "Toy.h"

seneca::Toy::Toy() = default;

void seneca::Toy::update(int numItems)
{
    toy_count = numItems;
}

seneca::Toy::Toy(const std::string &toy)
{
    int start = 0;
    char delimiter = ':';
    int end = toy.find(delimiter); 

    if (toy[0] != '#')
    {
        //ID
        order_id = stoi(toy.substr(start, end)); // TO REMOVE THE WHITESPACES AUTOMATICALLY

        //NAME
        start = (end + 1);
        end = toy.find(delimiter, start);
        toy_name = toy.substr(start, end - start);
        int first = toy_name.find_first_not_of(' ');
        int last = toy_name.find_last_not_of(' ');
        toy_name = toy_name.substr(first, last + 1);

        //COUNTER
        start = (end + 1);
        end = toy.find(delimiter, start);
        toy_count = stoi(toy.substr(start, end - start)); 

        //PRICE
        start = (end + 1);
        end = toy.find(delimiter, start);
        toy_price = stod(toy.substr(start, end - start)); 
    }
}
