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
    void info() const; // для обращения через элемент контейнера set метод должен быть константным
    bool operator < (Animal b) const; // для размещения элементов в контейнере set нужно определить оператор <
};

std::set<Animal> getAnimalsOfType(std::list<Animal> listOfAnimal, std::string typeofanimal);

#endif // ANIMAL_H