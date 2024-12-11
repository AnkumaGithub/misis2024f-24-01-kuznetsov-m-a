#ifndef ARRAYD_HPP
#define ARRAYD_HPP
#include <iosfwd>
#include <cstdint>
#include <cstring>
#include <iostream>

class ArrayD
{
private:
  ptrdiff_t len_ = 0;
  ptrdiff_t capacity_ = 0;
  double value_ = 0.0;
  double *data_ = nullptr;
public:
  // Constructors
  ArrayD() = default;
  ArrayD(const ptrdiff_t& olen);
  ArrayD(const ptrdiff_t olen,const double ovalue);
  // Copy constructor
  ArrayD(const ArrayD &other);
  //
  ArrayD& operator=(const ArrayD &other);
  // Destructor
  ~ArrayD();

  // Functions
  void Resize(const ptrdiff_t newmaxlen);
  void Insert(const ptrdiff_t index,const double &value);
  void Remove(const ptrdiff_t index);
  ptrdiff_t Size() const;
  bool Empty() const;
  double& operator[](const ptrdiff_t index);
  double operator[](const ptrdiff_t index) const;
};
#endif