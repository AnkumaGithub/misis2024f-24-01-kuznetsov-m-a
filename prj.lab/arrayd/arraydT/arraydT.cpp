#include "arraydT.hpp"
#include <iostream>
#include <cstdint>

template <class T>
ArrayDT<T>::ArrayDT(ptrdiff_t olen) :len(olen), maxlen(olen * 2)
{
    data = new T[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
}

template <class T>
ArrayDT<T>::ArrayDT(ptrdiff_t olen, T ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
{
    data = new T[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = value;}
}

template <class T>
ArrayDT<T>::ArrayDT(const ArrayDT &other) : len(other.len), maxlen(other.maxlen)
{
    data = new T[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) { data[i] = other.data[i]; }
}

template <class T>
ArrayDT<T>::~ArrayDT(){ delete[] data; }

template <class T>
void ArrayDT<T>::Resize(ptrdiff_t newmaxlen)
{
    ptrdiff_t* newdata = new ptrdiff_t[newmaxlen];
    for (ptrdiff_t i = 0; i < len; i++)
    {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    maxlen = newmaxlen;
}

template <class T>
ArrayDT<T>& ArrayDT<T>::operator=(const ArrayDT& other)
{
    if (this != &other)
    {
        delete[] data;
        maxlen = other.maxlen;
        len = other.len;
        ptrdiff_t* data = new ptrdiff_t[maxlen];
        for (ptrdiff_t i = 0; i < len; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
void ArrayDT<T>::Push_back(T &value)
{
    if (maxlen == len)
    {
        if (maxlen == 0){ maxlen = 1;}
        else { maxlen = maxlen * 2;}
    }
    Resize(maxlen);
    data[len + 1] = value;
}

template <class T>
void ArrayDT<T>::Pop_back()
{
    if (len > 0){len-=1;}
    else { std::cout << "Array is empty!" << std::endl; }
}

template <class T>
ptrdiff_t ArrayDT<T>::Size() const
{
    return len;
}

template <class T>
bool ArrayDT<T>::Empty() const
{
    return len == 0;
}

template <class T>
T& ArrayDT<T>::operator[](ptrdiff_t index)
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

template <class T>
T ArrayDT<T>::operator[](ptrdiff_t index) const
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

