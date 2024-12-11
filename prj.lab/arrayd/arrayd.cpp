#include <arrayd/arrayd.hpp>
#include <iostream>
#include <cstdint>
#include <cstring>

ArrayD::ArrayD(const ptrdiff_t& olen) :len_(olen), capacity_(olen * 2)
{
    if (len_ <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_ = new double[capacity_]{0.0};
}

ArrayD::ArrayD(const ptrdiff_t olen,const double ovalue) :len_(olen), capacity_(olen * 2), value_(ovalue)
{
    if (len_ <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_ = new double[capacity_]{value_};
}

ArrayD::ArrayD(const ArrayD &other) : len_(other.len_), capacity_(other.capacity_)
{
    data_ = new double[capacity_];
    std::memcpy(data_, other.data_, capacity_ * sizeof(*data_));
}

ArrayD::~ArrayD(){ delete[] data_; }

void ArrayD::Resize(const ptrdiff_t len)
{
    if (len < 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }
    if (capacity_ < len) {
        auto data = new double[len]{0.0};
        if (len_ > 0) {
            std::memcpy(data, data_, len_ * sizeof(*data_));
        }
        std::swap(data_, data);
        delete[] data;
        capacity_ = len;
    } else {
        if (len > len_) {
            std::memset(data_ + len, 0, (len - len_) * sizeof(*data_));
        }
    }
    len_ = len;
}

ArrayD& ArrayD::operator=(const ArrayD& other)
{
    if (this != &other)
    {
        Resize(other.len_);
        std::memcpy(data_, other.data_, len_ * sizeof(double));
    }
    return *this;
}

void ArrayD::Insert(const ptrdiff_t index,const double &value)
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    Resize(len_ + 1);
    if (index != len_ - 1)
    {
        std::memmove(data_ + index + 1, data_ + index, (len_ - index - 1) * sizeof(double));
    }
    data_[index] = value;
}

void ArrayD::Remove(const ptrdiff_t index)
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    if (index != len_ - 1)
    {
        std::memmove(data_ + index, data_ + index + 1, (len_ - index) * sizeof(double));
    }
    Resize(len_ - 1);
}

ptrdiff_t ArrayD::Size() const
{
    return len_;
}

bool ArrayD::Empty() const
{
    return len_ == 0;
}

double& ArrayD::operator[](const ptrdiff_t index)
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    return *(data_ + index);
}

double ArrayD::operator[](const ptrdiff_t index) const
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    return data_[index];
}


