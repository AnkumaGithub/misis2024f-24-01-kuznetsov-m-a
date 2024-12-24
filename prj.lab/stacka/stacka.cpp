#include <stacka/stacka.hpp>

#include <iostream>

bool StackA::IsEmpty(){
  return ind_ == 0;
}

bool StackA::IsFull(){
  return ind_ - 1 == capacity_;
}

void StackA::Clear()
{
  delete[] data_;
  ind_ = 0;
  capacity_ = 0;
}

StackA::StackA(const StackA& stack)
{
  if (stack.ind_ != 0)
  {
    capacity_ = stack.capacity_;
    ind_ = stack.ind_;
    Resize(ind_);
    std::memcpy(data_, stack.data_, ind_ * sizeof(*data_));
  }
  else
  {
    Clear();
  }
}

StackA& StackA::operator=(StackA& stack)
{
  if (this !=  &stack)
  {
    if (stack.ind_ != 0)
    {
      capacity_ = stack.capacity_;
      ind_ = stack.ind_;
      Resize(ind_);
      std::memcpy(data_, stack.data_, ind_ * sizeof(*data_));
    }
  }
  return *this;
}


void StackA::Resize(std::ptrdiff_t len){
  if (capacity_ < len) {
    auto data = new double[len]{0.0};
    if (ind_ > 0) {
      std::memcpy(data, data_, ind_ * sizeof(*data_));
    }
    std::swap(data_, data);
    delete[] data;
    capacity_ = len;
  } else {
    if (len > ind_) {
      std::memset(data_ + ind_, 0, (len - ind_) * sizeof(*data_));
    }
  }
  ind_ = len;
}

void StackA::Size(){
  std::cout << ind_ << std::endl;
}

void StackA::Push(double val){
  if (!IsEmpty()){
    if (IsFull()){
      Resize(ind_ + 2);
    }
    data_[ind_] = val;
    ind_ += 1;
  }
  else{
    Resize(ind_ + 2);
    data_[ind_] = val;
    ind_ += 1;
  }
}

double StackA::Top(){
  if (IsEmpty()){
    throw std::out_of_range("StackA::Top is empty");
  }
  return data_[ind_ - 1];
}

void StackA::Pop(){
  if (IsEmpty()){
    throw std::out_of_range("StackA::Pop is empty");
  }
  if (ind_ > 0){ ind_ -= 1; }
}