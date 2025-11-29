#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string firstN;
    std::string lastN;
    int day;
    int month;
    int year;
};


bool sortNames(const Student& a, const Student& b) {

    if (a.lastN != b.lastN) {
        return a.lastN < b.lastN;
    }
    if (a.firstN != b.firstN) {
        return a.firstN < b.firstN;
    }
    
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }

    return a.day < b.day;
}

bool sortDates(const Student& a, const Student& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day) {
        return a.day < b.day;
    }
    if (a.lastN != b.lastN) {
        return a.lastN < b.lastN;
    }
    return a.firstN < b.firstN;
}

int main() {

    int n;
    std::cin >> n;
    std::vector<Student> students(n);


    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].firstN >> students[i].lastN >> students[i].day 
                >> students[i].month >> students[i].year;
    }


    std::string sortby;
    std::cin >> sortby;


    if (sortby == "date") {
        std::sort(students.begin(), students.end(), sortDates);
    } else {
        std::sort(students.begin(), students.end(), sortNames);
    }

    for (const auto& s : students) {
        std::cout << s.firstN << " " << s.lastN << " " << s.day << "." << s.month << "." << s.year << "\n";
    }

    return 0;
}