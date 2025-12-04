#include <iostream>
#include <map>
#include "number.cpp"


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
        if((it->first) != ((it++)->first)){
            std::cout << "=\n";
        }
        it--;
        std::cout << "Фамилия: " << it->first << ", Номер: " << it->second << "\n";
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
