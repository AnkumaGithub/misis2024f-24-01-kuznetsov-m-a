#ifndef ARRAYD_HPP
#define ARRAYD_HPP
#include <iosfwd>
#include <cstdint>
#include <iostream>

class ArrayD
{
private:
  ptrdiff_t len = 0;
  ptrdiff_t maxlen = 0;
  double value = 0.0;
  double *data = nullptr;
public:
  // Constructors
  ArrayD(): data(nullptr), len(0) , maxlen(0), value(0) {}
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