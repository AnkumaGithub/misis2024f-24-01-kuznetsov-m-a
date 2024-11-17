#ifndef MARRAY_HPP
#define MARRAY_HPP
#include <iostream>


class Marray
{
private:
  int32_t len = 0;
  int32_t maxlen = 0;
  int32_t *data;
  void resize(int32_t newmaxlen);
public:
  // Constructors
  Marray() : data(nullptr), len(0) , maxlen(0) {}
  Marray(int32_t olen) :len(olen), maxlen(olen * 2)
  {
    data = new int32_t[maxlen];
    for (int32_t i = 0; i < len; i++) {data[i] = 0;}
  }
  // Copy constructor
  Marray(const Marray &other) : len(other.len), maxlen(other.maxlen)
  {
    data = new int32_t[maxlen];
    for (int32_t i = 0; i < len; i++) { data[i] = other.data[i]; }
  }
  // Destructor
  ~Marray(){ delete[] data; }

  // Functions
  void push_back(int32_t &value);
  void pop_back();
  int32_t size() const;
  bool empty() const;
  int& operator[](int index);

  Marray& operator=(const Marray &other);
};
#endif MARRAY_HPP