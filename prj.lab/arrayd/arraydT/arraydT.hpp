#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <cstdint>
#include <iostream>

template<class T>
class ArrayDT
{
private:
  ptrdiff_t len = 0;
  ptrdiff_t maxlen = 0;
  T value;
  T *data;
public:
  // Constructors
  ArrayDT(): data(nullptr), len(0) , maxlen(0), value(0) {}
  ArrayDT(ptrdiff_t olen);
  ArrayDT(ptrdiff_t olen, T ovalue);
  // Copy constructor
  ArrayDT(const ArrayDT &other);
  //
  ArrayDT& operator=(const ArrayDT &other);
  // Destructor
  ~ArrayDT();

  // Functions
  void Resize(ptrdiff_t newmaxlen);
  void Push_back(T &value);
  void Pop_back();
  ptrdiff_t Size() const;
  bool Empty() const;
  T& operator[](ptrdiff_t index);
  T operator[](ptrdiff_t index) const;
};
#include "arraydT.cpp"
#endif