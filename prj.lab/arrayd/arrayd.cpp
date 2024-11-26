#include <arrayd/arrayd.hpp>
#include <iostream>
#include <cstdint>

ArrayD::ArrayD(ptrdiff_t olen) :len(olen), maxlen(olen * 2)
{
    data = new double[maxlen];
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
}

ArrayD::ArrayD(ptrdiff_t olen, double ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
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

void ArrayD::Resize(ptrdiff_t newmaxlen)
{
    double* newdata = new double[newmaxlen];
    for (ptrdiff_t i = 0; i < len; i++)
    {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    maxlen = newmaxlen;
}

ArrayD& ArrayD::operator=(const ArrayD& other)
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

void ArrayD::Push_back(double &value)
{
    if (maxlen == len)
    {
        if (maxlen == 0){ maxlen = 1;}
        else { maxlen = maxlen * 2;}
    }
    Resize(maxlen);
    data[len + 1] = value;
}

void ArrayD::Pop_back()
{
    if (len > 0){len-=1;}
    else { std::cout << "Array is empty!" << std::endl; }
}

ptrdiff_t ArrayD::Size() const
{
    return len;
}

bool ArrayD::Empty() const
{
    return len == 0;
}

double& ArrayD::operator[](ptrdiff_t index)
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

double ArrayD::operator[](ptrdiff_t index) const
{
    if (index < 0 || index >= len)
    {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}


