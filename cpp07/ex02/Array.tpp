#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other)
{
    if (other._size)
        this->_elements = new T[other._size];
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        this->_size = other._size;
        if (this->_elements)
            delete[] this->_elements;
        if (this->_size){
            this->_elements = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; ++i)
                this->_elements[i] = other._elements[i];        
        }
        else 
            this->_elements = NULL;
    }
    return *this;
}

template <typename T>
Array<T>::~Array(){
    if (this->_elements)
        delete[] _elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
    if (index >= this->_size)
        throw OutOfBoundsException();
    return this->_elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= this->_size)
        throw OutOfBoundsException();
    return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const{
    return this->_size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw(){
    return "Out of bounds.";
}