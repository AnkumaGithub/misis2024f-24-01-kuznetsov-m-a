#include <stacka/stacka.hpp>

#include <iostream>

bool StackA::IsEmpty(){
  return capacity_ == 0;
}

bool StackA::IsFull(){
  return ind_ == capacity_;
}

void StackA::Resize(){
  capacity_ += 16;
  double* new_data = new double[capacity_]{0.0};
  //по умнее можно
  for (int i = 0; i < ind_; i++){
    new_data[i] = data_[i];
  }
  data_ = new_data;
}

void StackA::Push(double val){
  if (!IsEmpty()){
    if (IsFull()){
      Resize();
    }
    data_[ind_] = val;
    ind_ += 1;
  }
  Resize();
  data_[ind_] = val;
  ind_ += 1;
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