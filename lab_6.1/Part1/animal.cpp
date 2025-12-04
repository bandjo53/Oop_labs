#include "animal.h"

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