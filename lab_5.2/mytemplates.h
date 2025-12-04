#ifndef MYTEMPLATES
#define MYTEMPLATES

#include<iostream>

const int MAXSIZE = 100;

template <class T>
class Container
{
private:
    T data[MAXSIZE];
    int size;
public:
    Container();
    void add(T x);
    void del();
    void info();
    void sort();
};

template <class T>
Container<T>::Container()
{
    size = 0;
}


template <class T>
void Container<T>::add(T x)
{
    if(size < MAXSIZE){
        int flag = 0;
        for(int i=0;i<size;i++){
            if(data[i] == x){
                flag = 1;
                std::cout << data[i] << " already in cont ";
            }
        }
        if(flag == 0){
            data[size] = x;
            size ++;
        }    
    }else{
        std::cout << "Conteiner is full\n";
    }
}

template <class T>
void Container<T>::del()
{
    size--; // нет проверки на выход за пределы массива (для наглядности)
}

template <class T>
void Container<T>::info()
{
    std::cout << "\n";
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    if (size > 0)
    {
        std::cout << data[size - 1];
    }
    std::cout << "\n";
}

template <class T>
void Container<T>::sort()
{
    T element;
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if (data[j+1] < data[j])
            {
                element = data[j];
                data[j] = data[j+1];
                data[j+1] = element;
            }
        }
    }
}

#endif // MYTEMPLATES

