#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iosfwd>
#include <iostream>

template<class T>
class Marray
{
private:
  int32_t len = 0;
  int32_t maxlen = 0;
  T value;
  T *data;
  void resize(int32_t newmaxlen);
public:
  // Constructors
  Marray() : data(nullptr), len(0) , maxlen(0), value(0) {}
  Marray(int32_t olen) :len(olen), maxlen(olen * 2)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) {data[i] = 0;}
  }
  Marray(int32_t olen, T ovalue) :len(olen), maxlen(olen * 2), value(ovalue)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) {data[i] = value;}
  }
  // Copy constructor
  Marray(const Marray &other) : len(other.len), maxlen(other.maxlen)
  {
    data = new T[maxlen];
    for (int32_t i = 0; i < len; i++) { data[i] = other.data[i]; }
  }
  // Destructor
  ~Marray(){ delete[] data; }

  // Functions
  void push_back(T &value);
  void pop_back();
  int32_t size() const;
  bool empty() const;
  T& operator[](int index);

  Marray& operator=(const Marray &other);
};
#include <marray/marray.tpp>
#endif