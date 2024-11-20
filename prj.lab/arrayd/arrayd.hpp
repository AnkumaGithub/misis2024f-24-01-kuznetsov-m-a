#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <cstdint>
#include <iostream>

template<class T>
class Arrayd
{
private:
  ptrdiff_t len = 0;
  ptrdiff_t maxlen = 0;
  T value;
  T *data;
public:
  // Constructors
  Arrayd(): data(nullptr), len(0) , maxlen(0), value(0) {}
  Arrayd(ptrdiff_t olen);
  Arrayd(ptrdiff_t olen, T ovalue);
  // Copy constructor
  Arrayd(const Arrayd &other);
  //
  Arrayd& operator=(const Arrayd &other);
  // Destructor
  ~Arrayd();

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