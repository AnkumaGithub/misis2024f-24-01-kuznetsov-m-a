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

ptrdiff_t QueueA::get_capacity() const { return capacity; }
ptrdiff_t QueueA::get_size() const { return size; }

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

void QueueA::show_queue()
{
  for (ptrdiff_t i = head % capacity; i < (tail - 1) % capacity + 1; i++)
  {
    std::cout << unsigned(data[i]) << " ";
  }
}

void QueueA::Resize(){
  ptrdiff_t sch = 0;
  if (capacity == 0){sch = 1;}
  std::uint8_t* new_data = new std::uint8_t[capacity * 2 + sch];
  for (ptrdiff_t i = head; i < capacity; i++){
    new_data[i - head] = data[i];
  }
  for (ptrdiff_t i = 0; i < head; i++){
    new_data[i + head] = data[i];
  }
  data = new_data;
  head = 0;
  tail = capacity + sch;
  capacity = capacity * 2 + sch;
  //delete[] new_data;
}

void QueueA::Push(std::uint8_t& value){
  if (not(IsEmpty()))
  {
    if (size == capacity){
      Resize();
      data[tail] = value;
      tail = (tail + 1) % capacity;
      std::cout << head << " " << tail << " " << unsigned(value) << std::endl;
    }
    else
    {
      data[tail] = value;
      tail += 1;
      std::cout << head << " " << tail << " " << unsigned(value) << std::endl;
    }
    size += 1;
  }
  else
  {
    Resize();
    size += 1;
    data[0] = value;
  }
}

std::uint8_t& QueueA::Top(){
  if (not(IsEmpty()))
  {
    if (size == 0)
    {
      capacity = 0;
      Resize();
    }
    else
    {
      ptrdiff_t old_head = head;
      head += 1;
      head = head % capacity;
      size -= 1;
      return data[old_head];
    }
  }
  else
  {
    capacity = 0;
    head = 0;
    Resize();
    capacity = 0;
    std::cout << "queue is empty." << std::endl;
  }
}

void QueueA::Pop(){
  if (not(IsEmpty()))
  {
    if (size == 0)
    {
      capacity = 0;
      Resize();
    }
    else
    {
      ptrdiff_t old_head = head;
      head += 1;
      head = head % capacity;
      size -= 1;
    }
  }
  else
  {
    capacity = 0;
    head = 0;
    Resize();
    capacity = 0;
    std::cout << "queue is empty." << std::endl;
  }
}