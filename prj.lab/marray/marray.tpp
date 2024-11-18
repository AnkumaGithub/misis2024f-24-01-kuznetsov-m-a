#include <marray/marray.hpp>
#include <iostream>

template <class T>
void Marray<T>::resize(int32_t newmaxlen)
{
    int32_t* newdata = new int32_t[newmaxlen];
    for (int i = 0; i < len; i++)
    {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    maxlen = newmaxlen;
}

template <class T>
Marray<T>& Marray<T>::operator=(const Marray& other)
{
    if (this != &other)
    {
        delete[] data;
        maxlen = other.maxlen;
        len = other.len;
        int32_t* data = new int32_t[maxlen];
        for (int i = 0; i < len; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
void Marray<T>::push_back(T &value)
{
    if (maxlen == len)
    {
        if (maxlen == 0){ maxlen = 1;}
        else { maxlen = maxlen * 2;}
    }
    resize(maxlen);
    data[len + 1] = value;
}

template <class T>
void Marray<T>::pop_back()
{
    if (len > 0){len-=1;}
    else { std::cout << "Array is empty!" << std::endl; }
}

template <class T>
int32_t Marray<T>::size() const
{
    return len;
}

template <class T>
bool Marray<T>::empty() const
{
    return len == 0;
}

template <class T>
T& Marray<T>::operator[](int index)
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}


