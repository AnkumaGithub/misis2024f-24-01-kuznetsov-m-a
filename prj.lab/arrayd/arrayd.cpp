#include <arrayd/arrayd.hpp>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdexcept>

ArrayD::ArrayD(const std::ptrdiff_t len) :len_(len), capacity_(len)
{
    if (len <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_ = new double[len]{0.0};
}

ArrayD::ArrayD(const std::ptrdiff_t len,const double value) :len_(len), capacity_(len), value_(value)
{
    if (len <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_ = new double[len]{value};
}

ArrayD::ArrayD(const ArrayD &other) : capacity_(other.len_), len_(other.len_)
{
    data_ = new double[other.len_];
    std::memcpy(data_, other.data_, capacity_ * sizeof(*data_));
}

ArrayD::~ArrayD(){ delete[] data_; }

void ArrayD::Resize(const std::ptrdiff_t len)
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
            std::memset(data_ + len_, 0, (len - len_) * sizeof(*data_));
        }
    }
    len_ = len;
}

ArrayD& ArrayD::operator=(const ArrayD& other)
{
    if (this != &other)
    {
        Resize(other.len_);
        std::memcpy(data_, other.data_, len_ * sizeof(*data_));
    }
    return *this;
}

void ArrayD::Insert(const std::ptrdiff_t index,const double value)
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

void ArrayD::Remove(const std::ptrdiff_t index)
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

double& ArrayD::operator[](const std::ptrdiff_t index)
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    return *(data_ + index);
}

double ArrayD::operator[](const std::ptrdiff_t index) const
{
    if (index < 0 || index >= len_)
    {
        throw std::invalid_argument("ArrayD::operator[] - invalid index");
    }
    return data_[index];
}


