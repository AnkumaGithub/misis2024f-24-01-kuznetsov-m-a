#pragma once
#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <iostream>

template<class T>
class ArrayT
{
private:
    std::ptrdiff_t len_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::unique_ptr<T[]> data_ = nullptr;
public:
    // Constructors
    ArrayT() = default;
    explicit ArrayT(const std::ptrdiff_t len) :len_(len), capacity_(len)
    {
        if (len_ <= 0) {
            throw std::invalid_argument("ArrayT::ArrayT - non positive size");
        }
        data_ = std::make_unique<T[]>(len);
    }
    // Copy constructor
    ArrayT(const ArrayT &other) : len_(other.len_), capacity_(other.len_),
    data_(std::make_unique<T[]>(other.len_))
    {
        std::copy(other.data_.get(), other.data_.get() + len_, data_.get());
    }
    // Destructor
    ~ArrayT() = default;
    //

    ArrayT& operator=(const ArrayT& other)
    {
        if (this != &other) {
            Resize(other.len_);
            std::copy(other.data_.get(), other.data_.get() + len_, data_.get());
        }
        return *this;
    }

    // Functions
    void Resize(const std::ptrdiff_t len)
    {
        if (len < 0) {
            throw std::invalid_argument("ArrayT::Resize - negative size");
        }
        if (capacity_ < len) {
            auto buf = std::make_unique<T[]>(len);
            if (len_ > 0) {
                std::copy(data_.get(), data_.get() + len_, buf.get());
            }
            std::swap(data_, buf);
            capacity_ = len;
        } else {
            if (len_ < len) {
                std::fill(data_.get() + len_, data_.get() + len, T());
            }
        }
        len_ = len;
    }
    //
    void Insert(const std::ptrdiff_t index,const T &value)
    {
        if (index < 0 || len_ < index) {
            throw std::invalid_argument("ArrayT::Insert - invalid index");
        }
        Resize(len_ + 1);
        if (index != len_ - 1) {
            std::copy_backward(data_.get() + index,data_.get() + len_ - 1, data_.get() + len_);
        }
        data_[index] = value;
    }
    //
    void Remove(const std::ptrdiff_t index)
    {
        if (index < 0 || len_ <= index) {
            throw std::invalid_argument("ArrayD::Remove - invalid index");
        }
        if (index != len_ - 1) {
            std::copy(data_.get() + index + 1,data_.get() + len_, data_.get() + index);
        }
        Resize(len_ - 1);
    }
    //
    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return len_; }
    //
    std::ptrdiff_t MaxSize()
    {
        return capacity_;
    }
    //
    bool Empty()
    {
        return len_ == 0;
    }
    //
    const T& operator[](const std::ptrdiff_t index) const
    {
        if (index < 0 || len_ <= index) {
            throw std::invalid_argument("ArrayT::operator[] - invalid index");
        }
        return *(data_.get() + index);
    }
    //
    T& operator[](const std::ptrdiff_t index)
    {
        if (index < 0 || len_ <= index) {
            throw std::invalid_argument("ArrayT::operator[] - invalid index");
        }
        return *(data_.get() + index);
    }
};
#endif