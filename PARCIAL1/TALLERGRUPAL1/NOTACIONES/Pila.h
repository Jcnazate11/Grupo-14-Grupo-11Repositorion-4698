//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Notacion infija, prefija, postfija
// Autor: Jeanhela Nazate, Milena Maldonado, Johan Romo y Cristhopher Villamarin 
// Fecha de creación: 15/05/2022
// Fecha de modificación: 17/05/2022
// Github: https://github.com/Jcnazate11/-4698-Grupo14_Nazate_Maldonado_Estructuras/new/main/FuncionFinal
#ifndef PROYECTO_PILA_H
#define PROYECTO_PILA_H

#include <iostream>
#include <stdexcept>
#include "LDL.h"

using namespace std;

template<typename T>
class Pila //stack
{
public:
    Pila()
    {

    }
    ~Pila()
    {
        lista.clear();
    }
    //Lista vacia
    bool empty() const;
    //numero de nodos
    size_t size() const;
    //devuelve primer numero de la pila
    const T& top() const;
    void push(const T& element);
    void pop();

private:
    LDL<T> lista;
};

template<typename T>

bool Pila<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return lista.size();
}

template<typename T>
const T& Pila<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from empty stack.");
    }
    return lista.front();
}

template<typename T>
void Pila<T>::push(const T& element)
{
    lista.push_front(element);
}

template<typename T>
void Pila<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from empty stack.");
    }
    lista.pop_front();
}

#endif //PROYECTO_PILA_H
