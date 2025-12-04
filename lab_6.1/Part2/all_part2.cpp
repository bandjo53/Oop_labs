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


///////////////////////////////////////////////////////////////////


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


///////////////////////////////////////////////////////////////////


#include <iostream>
#include <map>

int main(){
    std::map<std::string, std::string> base_numbers;
    std::multimap<std::string, std::string> PhoneSet;

    std::multimap<std::string, std::string> SearchingbyLastname;
    std::map<std::string, std::string> SearchingbyPhone;

    base_numbers["+79151234567"] = "Иванов";
    base_numbers["+89265553322"] = "Петров";
    base_numbers["+79118765432"] = "Зайцев";
    base_numbers["+89992345678"] = "Кузнецов";
    base_numbers["+79123456789"] = "Смирнов";
    base_numbers["+74951234567"] = "Петров";
    base_numbers["+78005553535"] = "Лебедев";
    base_numbers["+88633010203"] = "Зайцев";
    base_numbers["+88124567890"] = "Петров";
    
    for (std::map<std::string, std::string>::iterator it = base_numbers.begin(); it != base_numbers.end(); it++)
    {
        std::cout << "Номер: " << it->first << ", Фамилия: " << it->second << std::endl;
    }

    
    std::cout << "----------------" << "\n";

    PhoneSet = GetPhoneToLastname(base_numbers);

    for (std::map<std::string, std::string>::iterator it = PhoneSet.begin(); it != PhoneSet.end(); it++)
    {
        std::cout << "Фамилия: " << it->first << ", Номер: " << it->second << "\n";
        if((it->first) != ((it++)->first)){
            std::cout << "=\n";
        }
        it--;
    }

    
    std::cout << "----------------" << "\n";

    SearchingbyLastname = SearchNumbersByLastname(base_numbers, "Петров");

    for (std::map<std::string, std::string>::iterator it = SearchingbyLastname.begin(); it != SearchingbyLastname.end(); it++)
    {
        std::cout << it->first<< "у принадлежит номер: " << it->second << std::endl;
    }
    
    
    std::cout << "----------------" << "\n";

    SearchingbyPhone = SearchLastnameByPhone(base_numbers, "+88633010203");
    
    for (std::map<std::string, std::string>::iterator it =  SearchingbyPhone.begin(); it !=  SearchingbyPhone.end(); it++)
    {
        std::cout << "Номер " << it->second << " принадлежит: " << it->first << std::endl;
    }
    
    return 0;
}