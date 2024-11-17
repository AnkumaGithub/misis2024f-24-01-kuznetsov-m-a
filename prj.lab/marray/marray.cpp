#include <marray/marray.hpp>
#include <iostream>

void Marray::resize(int32_t newmaxlen)
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

Marray& Marray::operator=(const Marray& other)
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

void Marray::push_back(int32_t &value)
{
    if (maxlen == len)
    {
        if (maxlen == 0){ maxlen = 1;}
        else { maxlen = maxlen * 2;}
    }
    resize(maxlen);
    data[len + 1] = value;
}

void Marray::pop_back()
{
    if (len > 0){len-=1;}
    else { std::cout << "Array is empty!" << std::endl; }
}

int32_t Marray::size() const
{
    return len;
}

bool Marray::empty() const
{
    return len == 0;
}

int& Marray::operator[](int index)
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}


