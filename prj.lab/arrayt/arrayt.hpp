#ifndef ARRAYT_HPP
#define ARRAYT_HPP
#include <iosfwd>
#include <cstdint>
#include <cstring>
#include <iostream>

template<class T>
class ArrayT
{
private:
    ptrdiff_t len = 0;
    ptrdiff_t capacity = 0;
    T value = T(0);
    std::unique_ptr<T[]> data = nullptr;
public:
    // Constructors
    ArrayT(): data(nullptr), len(0) , capacity(0), value(0) {}
    ArrayT(const ptrdiff_t olen) :len(olen), capacity(olen * 2)
    {
        data.reset(new T[capacity]{T()});
        for (ptrdiff_t i = 0; i < len; i++) {data[i] = 0;}
    }
    ArrayT(const ptrdiff_t olen,const T& ovalue) :len(olen), capacity(olen * 2), value(ovalue)
    {
        data.reset(new T[capacity]{T()});
        for (ptrdiff_t i = 0; i < len; i++) {data[i] = value;}
    }
    // Copy constructor
    ArrayT(const ArrayT &other) : len(other.len), capacity(other.capacity)
    {
        data.reset(new T[capacity]{T()});
        for (ptrdiff_t i = 0; i < len; i++) { data[i] = other.data[i]; }
    }
    // Destructor
    ~ArrayT() = default;
    //
    ArrayT& operator=(const ArrayT& other)
    {
        if (this != &other)
        {
            Resize(other.len);
            std::copy(other.data.get(), other.data.get() + len, data.get());
        }
        return *this;
    }

    ArrayT& operator=(const ArrayT* other)
    {
        data = other->data;
        return *this;
    }

    // Functions
    void Resize(const ptrdiff_t newlen)
    {
        data.reset(new T[newlen]{T()});
        len = newlen;
        if (newlen >= capacity)
        {
            capacity = capacity * 2;
        }
    }
    //
    void Insert(const ptrdiff_t index,const double &value)
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
                std::memmove(data.get() + index + 1, data.get() + index, len * sizeof(T));
            }
            *(data.get() + index) = value;
        }
    }
    //
    void Remove(const ptrdiff_t index)
    {
        if (index < 0 || index >= len) { std::cout << "Array is empty!" << std::endl;}
        else
        {
            if (index != len - 1) { std::memmove(data.get() + index, data.get() + index + 1, (len - index) * sizeof(T));}
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
    const T& operator[](ptrdiff_t index) const
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("index out of range");
        }
        return *(data.get() + index);
    }
    //
    T& operator[](ptrdiff_t index)
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("index out of range");
        }
        return *(data.get() + index);
    }
};
#endif