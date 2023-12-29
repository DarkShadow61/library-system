#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    int memberId;
    std::string name;
    std::string address;
    std::string email;

public:
    Member(int id, std::string name, std::string address, std::string email)
        : memberId(id), name(std::move(name)), address(std::move(address)), email(std::move(email)) {}

    int getId() const { return memberId; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getEmail() const { return email; }
};

#endif // MEMBER_H
