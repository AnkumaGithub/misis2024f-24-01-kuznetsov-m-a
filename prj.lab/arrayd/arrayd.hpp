#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <iostream>

template<class T>
class Arrayd
{
private:
  int32_t len = 0;
  int32_t maxlen = 0;
  T value;
  T *data;
  void resize(int32_t newmaxlen);
public:
  // Constructors
  Arrayd() : data(nullptr), len(0) , maxlen(0), value(0) {}
  Arrayd(int32_t olen) :len(olen), maxlen(olen * 2)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) {data[i] = 0;}
  }
  Arrayd(int32_t olen, T ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) {data[i] = value;}
  }
  // Copy constructor
  Arrayd(const Arrayd &other) : len(other.len), maxlen(other.maxlen)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) { data[i] = other.data[i]; }
  }
  // Destructor
  ~Arrayd(){ delete[] data; }

  // Functions
  void push_back(T &value);
  void pop_back();
  int32_t size() const;
  bool empty() const;
  T& operator[](int index);

  Arrayd& operator=(const Arrayd &other);
};
#include <arrayd/arrayd.tpp>
#endif