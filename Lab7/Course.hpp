// Course.h
#include <iostream>

using namespace std;

struct Course {

    enum dayOfWeek {
        MON, TUE, WED, THUR, FRI
    };

    /*Course Constructor*/
    Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);

    /*Course Copy Constructor*/
    Course(const Course &m);

    /*Overloaded assignment operator*/
    Course &operator=(Course m);

    /*Overloaded less than operator*/
    bool operator<(const Course &m) const;

    /*Overloaded equals operator*/
    bool operator==(const Course &m) const;

    string title; // Name of Course
    dayOfWeek day; // Day of Course
    unsigned int start_time; // Course start time in HHMM format
    unsigned int finish_time; // Course finish time in HHMM format

    /*Additional Getter to get days of week from char*/
    static dayOfWeek getDaysOfWeek(char day);

    /*Additional Getter to get char value from days of week*/
    static char getDayChar(dayOfWeek dofWeek);
};

// Helper operator for output
ostream &operator<<(ostream &os, const Course &m);