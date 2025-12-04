#include "number.h"

Number::Number()
{
    lastname = "NO NAME";
    phone_number = "NO NUMBER";
}

Number::Number(std::string name, std::string phone_number)
{
    this->lastname = lastname;
    this->phone_number = phone_number;
}

void Number::info() const
{
    std::cout << lastname.c_str() << ", " << phone_number.c_str() << "\n";
}

std::multimap<std::string, std::string> GetPhoneToLastname(std::map<std::string, std::string> base_numbers)
{
    std::multimap<std::string, std::string> PhoneSet;
    for(std::map<std::string, std::string>::iterator it = base_numbers.begin(); it != base_numbers.end(); it++){
        PhoneSet.insert({it->second, it->first});
    }
    return PhoneSet;
}

std::multimap<std::string, std::string> SearchNumbersByLastname(std::map<std::string, std::string> PhoneSet, std::string lastname){
    std::multimap<std::string, std::string> ContNumbers;
    for(std::map<std::string, std::string>::iterator it = PhoneSet.begin(); it != PhoneSet.end(); it++){
        if(it->second == lastname){
            ContNumbers.insert({it->second, it->first});
        }
    }
    return ContNumbers;
}

std::map<std::string, std::string> SearchLastnameByPhone(std::map<std::string, std::string> PhoneSet, std::string phone){
    std::map<std::string, std::string> ContPhone;
    for(std::map<std::string, std::string>::iterator it = PhoneSet.begin(); it != PhoneSet.end(); it++){
        if(it->first == phone){
            ContPhone.insert({it->second, it->first});
            break;
        }
    }
    return ContPhone;
}