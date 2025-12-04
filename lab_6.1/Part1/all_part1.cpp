#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <set>
#include <list>

class Animal
{
    public:
    std::string name;
    std::string typeofanimal;
    Animal();
    Animal(std::string name, std::string typeofanimal);
    void info() const;
    bool operator < (Animal b) const;
};

std::set<Animal> getAnimalsOfType(std::list<Animal> listOfAnimal, std::string typeofanimal);

#endif // ANIMAL_H

//////////////////////////////////////////////////////////////"

Animal::Animal()
{
    name = "NO NAME";
    typeofanimal = "NO TYPE";
}

Animal::Animal(std::string name, std::string typeofanimal)
{
    this->name = name;
    this->typeofanimal = typeofanimal;
}

void Animal::info() const
{
    std::cout << name.c_str() << ", " << typeofanimal.c_str() << "\n";
}

bool Animal::operator < (Animal b) const
{
    if (name != b.name)
    {
        return name < b.name;
    }
    else
    {
        return typeofanimal < b.typeofanimal;
    }
}

std::set<Animal> getAnimalsOfType(std::list<Animal> listOfAnimal, std::string typeofanimal)
{
    std::set<Animal> animalSet;
    
    for (std::list<Animal>::iterator it = listOfAnimal.begin(); it != listOfAnimal.end(); it++)
    {
        if(it->typeofanimal == typeofanimal)
        {
            animalSet.insert(*it);
        }
    }
    
    return animalSet;
}

/////////////////////////////////////////////////////////////

// 1. Определить класс «Домашнее животное», данные которого включают имя и тип
// животного. Тип животного задавать перечислением типа «Кошка», «Собака», «Хомяк» и
// т.п. Написать функцию, формирующую по заданному списку (шаблонный класс list)
// объектов класса множество (шаблонный класс set) из элементов списка. Функция
// включает в множество животных заданного типа.
// Примечание: для того, чтобы объекты могли быть добавлены в множество в их классе
// должна быть определен оператор сравнения «меньше» в константной форме.

#include <iostream>

using namespace std;

int main()
{
    Animal b1;
    Animal b2("Hyper", "Cat");
    Animal b3("Kelvin", "Dog");
    Animal b4("Tom", "Cat");
    Animal b5("Ivan", "Snake");
    Animal b6("Zevs", "Dog");
    Animal b7("Vasiliy", "Hamster");
    Animal b8("Murka", "Cat");
    Animal b9("Tosha", "Hamster");
    
    std::list<Animal> AnimalList;
    std::set<Animal> AnimalSet;

    AnimalList.push_back(b1);
    AnimalList.push_back(b2);
    AnimalList.push_back(b3);
    AnimalList.push_back(b4);
    AnimalList.push_back(b5);
    AnimalList.push_back(b6);
    AnimalList.push_back(b7);
    AnimalList.push_back(b8);
    AnimalList.push_back(b9);
    
    for (std::list<Animal>::iterator it = AnimalList.begin(); it != AnimalList.end(); it++)
    {
        it->info();
    }

    std::cout << "----------------" << "\n";

    // std::cout << "Enter the type of animal: ";
    // std::string Choosetype = "NO TYPE";
    // std::cin >> Choosetype;
    
    AnimalSet = getAnimalsOfType(AnimalList, "Cat");

    for (std::set<Animal>::iterator it = AnimalSet.begin(); it != AnimalSet.end(); it++)
    {
        it->info();
    }

    return 0;
}
