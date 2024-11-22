#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <cstdint>
#include <iostream>

template<class T>
class ArrayD
{
private:
  ptrdiff_t len = 0;
  ptrdiff_t maxlen = 0;
  T value;
  T *data;
public:
  // Constructors
  ArrayD(): data(nullptr), len(0) , maxlen(0), value(0) {}
  ArrayD(ptrdiff_t olen);
  ArrayD(ptrdiff_t olen, T ovalue);
  // Copy constructor
  ArrayD(const ArrayD &other);
  //
  ArrayD& operator=(const ArrayD &other);
  // Destructor
  ~ArrayD();

  // Functions
  void Resize(ptrdiff_t newmaxlen);
  void Push_back(T &value);
  void Pop_back();
  ptrdiff_t Size() const;
  bool Empty() const;
  T& operator[](ptrdiff_t index);
  T operator[](ptrdiff_t index) const;
};
#include <arrayd/arrayd.cpp>
#endif