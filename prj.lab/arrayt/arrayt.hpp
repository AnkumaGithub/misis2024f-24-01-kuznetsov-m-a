#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <cstdint>
#include <iostream>

template<class T>
class ArrayT
{
private:
    ptrdiff_t len = 0;
    ptrdiff_t maxlen = 0;
    T value = T(0);
    T *data = nullptr;
public:
    // Constructors
    ArrayT(): data(nullptr), len(0) , maxlen(0), value(0) {}
    ArrayT(const ptrdiff_t olen) :len(olen), maxlen(olen * 2)
    {
        data = new T[maxlen];
        for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
    }
    ArrayT(const ptrdiff_t olen,const T& ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
    {
        data = new T[maxlen];
        for (ptrdiff_t i = 0; i < len; i++) {data[i] = value;}
    }
    // Copy constructor
    ArrayT(const ArrayT &other) : len(other.len), maxlen(other.maxlen)
    {
        data = new T[maxlen];
        for (ptrdiff_t i = 0; i < len; i++) { data[i] = other.data[i]; }
    }
    // Destructor
    ~ArrayT(){ delete[] data; }
    //
    ArrayT& operator=(const ArrayT& other)
    {
        if (this != &other)
        {
            Resize(other.len);
            memcpy(data, other.data, len * sizeof(double));
        }
        return *this;
    }

    // Functions
    void Resize(const ptrdiff_t newlen)
    {
        T* newdata = new T[newlen];
        for (ptrdiff_t i = 0; i < len; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        len = newlen;
        if (newlen >= maxlen)
        {
            maxlen = maxlen * 2;
        }
    }
    //
    void Insert(const ptrdiff_t index,const double &value)
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
    //
    void Remove(const ptrdiff_t index)
    {
        if (index < 0 || index >+ len) { std::cout << "Array is empty!" << std::endl;}
        else
        {
            if (index != len - 1) { std::memmove(data + index, data + index + 1, (len - index) * sizeof(double));}
        }
        Resize(len - 1);
    }
    //
    ptrdiff_t Size() const
    {
        return len;
    }
    //
    ptrdiff_t MaxSize() const
    {
        return len;
    }
    //
    bool Empty() const
    {
        return len == 0;
    }
    //
    T& operator[](ptrdiff_t index)
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("index out of range");
        }
        return data[index];
    }
    //
    T operator[](ptrdiff_t index) const
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("index out of range");
        }
        return data[index];
    }
};
#endif