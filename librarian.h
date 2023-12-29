#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
#include <string>
#include <limits>

class Librarian {
private:
    std::string name;
    std::string address;
    std::string email;
    int staffId;
    double salary;

public:
    Librarian() : staffId(0), salary(0.0) {}

    void inputDetails() {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Enter your address: ";
        std::getline(std::cin, address);
        std::cout << "Enter your email: ";
        std::getline(std::cin, email);
        std::cout << "Enter your staff ID: ";
        std::cin >> staffId;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your salary: ";
        std::cin >> salary;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

#endif // LIBRARIAN_H
