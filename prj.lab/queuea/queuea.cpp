#include <queuea/queuea.hpp>
#include <iostream>

QueueA::QueueA()
{
  capacity = 0;
  head = 0;
  tail = 1;
  data = new std::uint8_t[capacity];
}

bool QueueA::IsEmpty() const {
  return capacity == 0;
}

ptrdiff_t QueueA::get_size() const { return capacity; }

void QueueA::move_head(){
  head += 1;
  if (head >= capacity){
    head = 0;
  }
}
void QueueA::move_tail(){
  tail += 1;
  if (tail > capacity){
    tail = 0;
  }
}

bool QueueA::IsEnough(){
  if ((head % capacity) == (tail % capacity) || capacity == 0){ return true; }
  else { return false; }
}

void QueueA::Resize(){
  ptrdiff_t sch = 0;
  if (capacity == 0){sch = 1;}
  std::cout << "???" << std::endl;
  std::uint8_t* new_data = new std::uint8_t[capacity * 2 + sch];
  std::cout << "!!!" << std::endl;
  for (ptrdiff_t i = head; i < capacity; i++){
    new_data[i - head] = data[i];
  }
  for (ptrdiff_t i = 0; i < head; i++){
    new_data[i + head] = data[i];
  }
  std::cout << "!!!" << std::endl;
  data = new_data;
  head = 0;
  tail = capacity + sch;
  capacity = capacity * 2 + sch;
  std::cout << "!!!" << std::endl;
  //delete[] new_data;
}

void QueueA::Push(std::uint8_t& value){
  if (not(IsEmpty()))
  {
    if (tail % capacity == head % capacity){
      std::cout << "!!! " << head << " " << capacity << " " << tail << std::endl;
      Resize();
      std::cout << "!!!" << std::endl;
      data[tail] = value;
      std::cout << "!!!" << std::endl;
    }
    else
    {
      data[tail] = value;
      tail += 1;
    }
  }
  else
  {
    Resize();
    data[0] = value;
  }
}

std::uint8_t& QueueA::Top(){
  if (not(IsEmpty()))
  {
    if (head % capacity == tail % capacity - 1)
    {
      capacity = 0;
      head += 1;
      return data[head - 1];
    }
    else
    {
      head += 1;
      head = head % capacity;
      return data[head - 1];
    }
  }
  else
  {
    std::cout << "queue is empty." << std::endl;
    std::uint8_t b = 0;
    return b;
  }
}

void QueueA::Pop(){
  if (not(IsEmpty()))
  {
    if (head % capacity == tail % capacity - 1)
    {
      capacity = 0;
      head += 1;
    }
    else
    {
      head += 1;
      head = head % capacity;
    }
  }
  else
  {
    std::cout << "queue is empty." << std::endl;
  }
}