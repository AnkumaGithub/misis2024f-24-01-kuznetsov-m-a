#include <arrayd/arrayd.hpp>
#include <iostream>
#include <cstdint>
#include <cstring>

ArrayD::ArrayD(const ptrdiff_t& olen) :len(olen), maxlen(olen * 2)
{
    data = new double[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
}

ArrayD::ArrayD(const ptrdiff_t olen,const double ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
{
    data = new double[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = value;}
}

ArrayD::ArrayD(const ArrayD &other) : len(other.len), maxlen(other.maxlen)
{
    data = new double[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) { data[i] = other.data[i]; }
}

ArrayD::~ArrayD(){ delete[] data; }

void ArrayD::Resize(const ptrdiff_t newlen)
{
    double* newdata = new double[newlen];
    memcpy(newdata, data, len * sizeof(double));
    delete[] data;
    data = newdata;
    len = newlen;
    if (newlen >= maxlen)
    {
        maxlen = maxlen * 2;
    }
}

ArrayD& ArrayD::operator=(const ArrayD& other)
{
    if (this != &other)
    {
        Resize(other.len);
        memcpy(data, other.data, len * sizeof(double));
    }
    return *this;
}

void ArrayD::Insert(const ptrdiff_t index,const double &value)
{
    if (index < 0 || index >= len)
    {
        std::cerr << "index out of range" << std::endl;
    }
    else
    {
        Resize(len + 1);
        if (index != len)
        {
            std::memmove(data + index + 1, data + index, len * sizeof(double));
        }
        data[index] = value;
    }
}

void ArrayD::Remove(const ptrdiff_t index)
{
    if (index < 0 || index >= len) { std::cout << "Array is empty!" << std::endl;}
    else
    {
        if (index != len - 1) { std::memmove(data + index, data + index + 1, (len - index) * sizeof(double));}
    }
    Resize(len - 1);
}

ptrdiff_t ArrayD::Size() const
{
    return len;
}

bool ArrayD::Empty() const
{
    return len == 0;
}

double& ArrayD::operator[](const ptrdiff_t index)
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

double ArrayD::operator[](const ptrdiff_t index) const
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}


