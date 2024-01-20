//Name : Hla Myint Myat
//Email: hmyat1@myseneca.ca
//ID : 185923216
//DATE : 19.1.24

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "event.h"
using namespace std;

size_t g_sysClock = 0 ;

namespace seneca {

    Event::Event()
    {
        numOfSeconds = 0;
        descriptionOfEvent = nullptr;
    }

    void Event::display()const
    {
        int totalHours, totalMinutes, totalSeconds;
        static int INFO = 1;
        totalHours = numOfSeconds / 3600;
        totalMinutes = numOfSeconds / 60;
        totalMinutes = totalMinutes % 60;
        totalSeconds = numOfSeconds % 60;

        cout.setf(ios::right);
        cout.fill(' ');
        cout.width(2);
        cout << INFO << ". ";
        cout.unsetf(ios::right);

        if (descriptionOfEvent == nullptr || descriptionOfEvent[0] == '\0')
        {
            cout << "| No Event |" << endl;
        }
        else
        {
            cout.setf(ios::right);
            cout.fill('0');
            cout.width(2);
            cout << totalHours << ":";
            cout.fill('0');
            cout.width(2);
            cout << totalMinutes << ":";
            cout.fill('0');
            cout.width(2);
            cout << totalSeconds << " => ";
            cout.unsetf(ios::right);
            cout << descriptionOfEvent << endl;
        }
        INFO++;

    }
    Event& Event::operator=(const Event& eve)
    {
        if (this != &eve)
        {
            delete[] descriptionOfEvent;
            set(eve.descriptionOfEvent);
            numOfSeconds = eve.numOfSeconds;
        }
        return *this;
    }

    Event::Event(const Event& eve)
    {
        delete[] descriptionOfEvent;
        set(eve.descriptionOfEvent);
        numOfSeconds = eve.numOfSeconds;
    }

    void Event::set(const char* add)
    {
        if (add == nullptr || add[0] == '\0')
        {
            delete[] descriptionOfEvent;
            numOfSeconds = 0;
            descriptionOfEvent = nullptr;
        }
        else
        {
            delete[] descriptionOfEvent;
            descriptionOfEvent = nullptr;
            descriptionOfEvent = new char[strlen(add) + 1];
            strcpy(descriptionOfEvent, add);
            descriptionOfEvent[strlen(add)] = '\0';
            numOfSeconds = g_sysClock;
        }
    }
    
    Event::~Event()
    {
        delete[] descriptionOfEvent;
        descriptionOfEvent = nullptr;
    }
}
