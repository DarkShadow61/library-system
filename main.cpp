#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Assuming the Librarian and Member classes are defined in their respective header files.
#include "Librarian.h"
#include "Member.h"

std::vector<Member> members;

void addMember() {
    int id;
    std::string name, address, email;
    
    std::cout << "Enter member ID (or 0 to go back): ";
    std::cin >> id;
    if (id == 0) return;
    std::cin.ignore();

    std::cout << "Enter member name: ";
    std::getline(std::cin, name);

    std::cout << "Enter member address: ";
    std::getline(std::cin, address);

    std::cout << "Enter member email: ";
    std::getline(std::cin, email);

    members.emplace_back(id, name, address, email);
    std::cout << "Member added successfully!\n";

    // Display the table of members
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(30) << "Address"
              << std::setw(30) << "Email" << std::endl;

    for (const auto& member : members) {
        std::cout << std::left << std::setw(10) << member.getId()
                  << std::setw(20) << member.getName()
                  << std::setw(30) << member.getAddress()
                  << std::setw(30) << member.getEmail() << std::endl;
    }
}

bool isMemberExist(int memberId) {
    for (const auto& member : members) {
        if (member.getId() == memberId) {
            return true;
        }
    }
    return false;
}
void showBookTypes() {
    std::cout << "Select the type of book to issue:" << std::endl;
    std::cout << " 1. Science Fiction" << std::endl;
    std::cout << " 2. Satire" << std::endl;
    std::cout << " 3. Drama" << std::endl;
    std::cout << " 4. Action and Adventure" << std::endl;
    std::cout << " 5. Romance" << std::endl;
    std::cout << " 6. Mystery" << std::endl;
    std::cout << " 7. Horror" << std::endl;
    std::cout << " 8. Health" << std::endl;
    std::cout << " 9. Guide" << std::endl;
    std::cout << "10. Diaries" << std::endl;
    std::cout << "11. Comics" << std::endl;
    std::cout << "12. Journals" << std::endl;
    std::cout << "13. Biographies" << std::endl;
    std::cout << "14. Fantasy" << std::endl;
    std::cout << "15. History" << std::endl;
    std::cout << "16. Science" << std::endl;
    std::cout << "17. Art" << std::endl;
    
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // You can add further logic based on the selected book type
    // For now, just acknowledging the selection
    if (choice >= 1 && choice <= 17) {
        std::cout << "Book type " << choice << " selected." << std::endl;
    } else {
        std::cout << "Invalid book type selected." << std::endl;
    }
}

void issueBook() {
    int memberId;
    std::cout << "Enter member ID to issue a book: ";
    std::cin >> memberId;

    if (isMemberExist(memberId)) {
        std::cout << "Match successful. Proceeding to issue a book.\n";
        showBookTypes();
    } else {
        std::cout << "Member ID does not exist. Please get your ID from Add Member.\n";
    }
}


int main() {
    Librarian librarian;
    librarian.inputDetails();

    int choice;
    do {
        std::cout << "\nWelcome to the Library Management System" << std::endl;
        std::cout << "1. Add Member" << std::endl;
        std::cout << "2. Issue Book" << std::endl;
        std::cout << "3. Return Book" << std::endl;
        std::cout << "4. Record of Borrowing Books" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
               issueBook();
                break;
            case 3:
                // Return Book functionality
                break;
            case 4:
                // Record of Borrowing Books functionality
                break;
            case 5:
                std::cout << "Exiting the Library Management System.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
