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
  double value;
  double *data;
public:
  // Constructors
  ArrayD(): data(nullptr), len(0) , maxlen(0), value(0) {}
  ArrayD(ptrdiff_t olen);
  ArrayD(ptrdiff_t olen, double ovalue);
  // Copy constructor
  ArrayD(const ArrayD &other);
  //
  ArrayD& operator=(const ArrayD &other);
  // Destructor
  ~ArrayD();

  // Functions
  void Resize(ptrdiff_t newmaxlen);
  void Push_back(double &value);
  void Pop_back();
  ptrdiff_t Size() const;
  bool Empty() const;
  double& operator[](ptrdiff_t index);
  double operator[](ptrdiff_t index) const;
};
#endif