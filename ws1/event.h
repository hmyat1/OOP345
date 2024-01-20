//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 19.1.24

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_EVENT_H_
#define SENECA_EVENT_H_

extern size_t g_sysClock;
namespace seneca{
    class Event {
        char* descriptionOfEvent{};
        unsigned int numOfSeconds;
    public:
        Event();
        void display()const;
        void set(const char* add = nullptr);
        Event(const Event&);
        Event& operator=(const Event&);
        ~Event();
    };
}
#endif
