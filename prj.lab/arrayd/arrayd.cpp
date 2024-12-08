#include <arrayd/arrayd.hpp>
#include <iostream>
#include <cstdint>
#include <cstring>

ArrayD::ArrayD(const ptrdiff_t& olen) :len(olen), maxlen(olen * 2)
{
    data.reset(new double[maxlen]{double()});
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
}

ArrayD::ArrayD(const ptrdiff_t olen,const double ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
{
    data.reset(new double[maxlen]{double()});
    for (ptrdiff_t i = 0; i < len; i++) {data[i] = value;}
}

ArrayD::ArrayD(const ArrayD &other) : len(other.len), maxlen(other.maxlen)
{
    data.reset(new double[maxlen]{double()});
    for (ptrdiff_t i = 0; i < len; i++) { data[i] = other.data[i]; }
}

void ArrayD::Resize(const ptrdiff_t newlen)
{
    data.reset(new double[newlen]{double()});
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
        std::copy(other.data.get(), other.data.get() + len, data.get());
    }
    return *this;
}

void ArrayD::Insert(const ptrdiff_t index,const double &value)
{
    if (index < 0 || index > len)
    {
        std::cerr << "index out of range" << std::endl;
    }
    else
    {
        Resize(len + 1);
        if (index != len)
        {
            std::memmove(data.get() + index + 1, data.get() + index, len * sizeof(double));
        }
        *(data.get() + index) = value;
    }
}

void ArrayD::Remove(const ptrdiff_t index)
{
    if (index < 0 || index >= len) { std::cout << "Array is empty!" << std::endl;}
    else
    {
        if (index != len - 1) { std::memmove(data.get() + index, data.get() + index + 1, (len - index) * sizeof(double));}
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


