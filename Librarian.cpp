#include "Librarian.h"

Librarian::Librarian() : staffId(0), salary(0.0) {}

void Librarian::inputDetails() {
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your address: ";
    std::getline(std::cin, address);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
    
    std::cout << "Enter your staff ID: ";
    while (!(std::cin >> staffId)) {
        std::cout << "Invalid input. Please enter a number for staff ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter your salary: ";
    while (!(std::cin >> salary)) {
        std::cout << "Invalid input. Please enter a number for salary: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
}
