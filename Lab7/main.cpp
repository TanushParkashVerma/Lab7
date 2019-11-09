#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> &m) {
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    auto startCourse = m.begin();
    auto endCourse = m.end();
    ostream_iterator<Course> os(cout, "\n");
    std::copy(startCourse, endCourse, os);
}

int main() {
    //TODO read from courses.txt
    ifstream f;
    f.open("../courses.txt");
    string title;
    string courseData;
    char day;
    unsigned int startTime;
    unsigned int finishTime;

    //courses of type vector
    vector<Course> courses;

    //TODO store courseData in an STL container
    while (f >> title >> day >> startTime >> finishTime) {
        Course c(title, Course::getDaysOfWeek(day), startTime, finishTime);
        courses.push_back(c);
    }
    //TODO sort your STL container with the sort algorithm
    sort(courses.begin(), courses.end());

    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    for (auto it = courses.begin(); it != courses.end() - 1; it++) {
        for (auto iter = it + 1; iter != courses.end(); iter++) {
            if (*it == *iter) {
                cout << "CONFLICT: \n";
                cout << *it << "\n";
                cout << *iter << "\n\n";
            }
        }
    }
    //TODO print out schedule
    printSchedule(courses);

    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}