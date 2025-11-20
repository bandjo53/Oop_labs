/*
 * Описать шаблон класса для хранения данных. Данные должны храниться, например, в виде массива.
 * Шаблон должен включать в себя функции добавления данных, удаления данных, вывода данных на консоль ( info() )
 * и метод, осуществляющий  сортировку элементов по возрастанию. Продемонстрировать работу шаблона на объектах
 * как встроенного типа, так и собственного класса. Для этого создать собственный класс и перегрузить в нём
 * нужные функции-операции
 */

#include <iostream>
#include "mytemplates.h"
#include "person.cpp"

using namespace std;

int main()
{
    Container<int> contInt;

    contInt.add(10);
    contInt.add(3);
    contInt.add(3);
    contInt.add(2);
    contInt.add(5);
    contInt.info();

    contInt.del();
    contInt.del();
    contInt.info();

    Container<Person> contPerson;

    contPerson.add(Person("Ivan", 1984));
    contPerson.add(Person("Petr", 1988));
    contPerson.add(Person("Olga", 2010));
    // contPerson.add(Person("Vasily", 2001));
    // contPerson.add(Person("Timofey", 1999));
    // contPerson.add(Person("Kostya", 2005));
    contPerson.info();

    // contPerson.del();
    // contPerson.del();
    

    // contPerson.sort();
    // contPerson.info();

    return 0;
}

