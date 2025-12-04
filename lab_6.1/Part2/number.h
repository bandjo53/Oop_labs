#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <set>
#include <list>
#include <map>

class Number
{
    public:
    std::string lastname;
    std::string phone_number;
    Number();
    Number(std::string name , std::string phone_number);
    void info() const;
    bool operator < (Number b) const;
};

std::multimap<std::string, std::string> GetPhoneToLastname(std::map<std::string, std::string> base_numbers);

std::multimap<std::string, std::string> SearchNumbersByLastname(std::map<std::string, std::string> PhoneSet, std::string lastname);

std::map<std::string, std::string> SearchLastnameByPhone(std::map<std::string, std::string> PhoneSet, std::string phone);

#endif // NUMBER_H