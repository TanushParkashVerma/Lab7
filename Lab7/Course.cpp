#include "Course.hpp"

using namespace std;

/*Course Constructor*/
Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title(title), day(day),
                                                                                                 start_time(start_time),
                                                                                                 finish_time(
                                                                                                         finish_time) {
}

/*Course Copy Constructor*/
Course::Course(const Course &m) : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {
}

/*Overloaded assignment operator*/
Course &Course::operator=(Course m) {
    //TODO implement the operator
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}


/*Overloaded equals operator*/
bool Course::operator==(const Course &m) const {
    //TODO implement the operator
    if (this->day == m.day) {
        if (this->start_time == m.start_time || this->finish_time == m.finish_time) {
            return true;
        }
    }
    return false;
}

/*Overloaded less than operator*/
bool Course::operator<(const Course &m) const {
    //TODO implement the operator
    if (this->day != m.day) {
        return this->day < m.day;
    } else {
        return this->start_time < m.start_time;
    }

}

/*Additional Getter to get days of week from char*/
Course::dayOfWeek Course::getDaysOfWeek(char day) {
    if (day == 'M') {
        return Course::dayOfWeek::MON;
    }
    if (day == 'T') {
        return Course::dayOfWeek::TUE;
    }
    if (day == 'W') {
        return Course::dayOfWeek::WED;
    }
    if (day == 'H') {
        return Course::dayOfWeek::THUR;
    }
    if (day == 'F') {
        return Course::dayOfWeek::FRI;
    }

}

/*Additional Getter to get char value from days of week*/
char Course::getDayChar(Course::dayOfWeek dofWeek) {
    if (dofWeek == MON) {
        return 'M';
    }
    if (dofWeek == TUE) {
        return 'T';
    }
    if (dofWeek == WED) {
        return 'W';
    }
    if (dofWeek == THUR) {
        return 'H';
    }
    if (dofWeek == FRI) {
        return 'F';
    }

}

// Helper operator for output
ostream &operator<<(ostream &os, const Course &m) {
    //TODO implement the operator
    os << m.title << " ";
    os << Course::getDayChar(m.day) << " ";
    os << m.start_time << " ";
    os << m.finish_time;
    return os;
}