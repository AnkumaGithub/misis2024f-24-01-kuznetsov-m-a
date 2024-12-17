#pragma once
#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstddef>
#include <iostream>

class ArrayD
{
private:
  std::ptrdiff_t len_ = 0;
  std::ptrdiff_t capacity_ = 0;
  double value_ = 0.0;
  double* data_ = nullptr;
public:
  // Constructors
  ArrayD() = default;
  ArrayD(const std::ptrdiff_t len);
  ArrayD(const std::ptrdiff_t len,const double value);
  // Copy constructor
  ArrayD(const ArrayD& other);
  //
  ArrayD& operator=(const ArrayD& other);
  // Destructor
  ~ArrayD();

  // Functions
  void Resize(const std::ptrdiff_t len);
  void Insert(const std::ptrdiff_t index, const double value);
  void Remove(const std::ptrdiff_t index);
  std::ptrdiff_t Size() const;
  bool Empty() const;
  [[nodiscard]] double& operator[](const std::ptrdiff_t index);
  [[nodiscard]] double operator[](const std::ptrdiff_t index) const;
};
#endif //ARRAYD_HPP