#ifndef STACKA_H
#define STACKA_H

#include <memory>


class StackA{
  private:
    double* data_ = nullptr;
    std::ptrdiff_t ind_ = 0;
    std::ptrdiff_t capacity_ = 0;
  public:
    StackA() : data_(nullptr), ind_(0), capacity_(0) {};
    //copy constructor
    StackA(const StackA& stack);
    //destructor
    ~StackA(){
      delete[] data_;
    };
    //добавит копирование и =
    void Push(double val);
    bool IsEmpty();
    bool IsFull();
    void Resize();
    void Pop();
    double Top();
    void Size();
  };
#endif // STACKA_H