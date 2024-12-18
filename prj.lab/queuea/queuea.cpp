#include <queuea/queuea.hpp>
#include <iostream>
#include <algorithm>
#include <queue>

QueueA::~QueueA()
{
  delete[] data;
}

QueueA::QueueA()
{
  capacity = 0;
  head = 0;
  tail = 1;
  data = new T[capacity];
}

std::ptrdiff_t QueueA::Count_size() const
{
  if (IsEmpty())
  {
    return 0;
  }
  else
  {
    return (tail - head + size) % size;
  }
}

void QueueA::Swap(QueueA&& other) noexcept
{
  std::swap(capacity, other.capacity);
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(data, other.data);
}


QueueA& QueueA::operator=(const QueueA& other)
{
if (this != &other){
  capacity = other.Count_size();
  head = other.head;
  tail = other.tail;
  delete[] data;
  data = new T[capacity];
  std::copy(other.data, other.data + capacity, data);
}
  return *this;
}
QueueA& QueueA::operator=(QueueA&& other)
{
  if (this !=& other)
  {
    Swap(std::move(other));
  }
  return *this;
}

QueueA::QueueA(const QueueA& other){
  if (!IsEmpty())
  {
    capacity = other.capacity;
    head = other.head;
    tail = other.tail;
    delete[] data;
    data = new T[capacity];
    std::copy(other.data, other.data + capacity, data);
  }
}

QueueA::QueueA(QueueA&& other) noexcept
{
  Swap(std::move(other));
}

bool QueueA::IsEmpty() const {
  return capacity == 0;
}

std::ptrdiff_t QueueA::get_capacity() const { return capacity; }
std::ptrdiff_t QueueA::get_size() const { return size; }

bool QueueA::IsEnough(){
  if ((head % capacity) == (tail % capacity) || capacity == 0){ return true; }
  return false;
}

void QueueA::show_queue()
{
  for (std::ptrdiff_t i = head % capacity; i < (tail - 1) % capacity + 1; i++)
  {
    std::cout << unsigned(data[i]) << " ";
  }
}

void QueueA::Clear()
{
  std::ptrdiff_t capacity = 0;
  std::ptrdiff_t size = 0;
  std::ptrdiff_t head = 0;
  std::ptrdiff_t tail = 1;
}


void QueueA::Resize(){
  ptrdiff_t sch = 0;
  if (capacity == 0){sch = 1;}
  T* new_data = new T[capacity * 2 + sch];
  for (std::ptrdiff_t i = head; i < capacity; i++){
    new_data[i - head] = data[i];
  }
  for (std::ptrdiff_t i = 0; i < head; i++){
    new_data[i + head] = data[i];
  }
  data = new_data;
  head = 0;
  tail = capacity + sch;
  capacity = capacity * 2 + sch;
  //std::free(new_data);
}

void QueueA::Push(const T& value){
  if (IsEmpty() != true)
  {
    if (size == capacity){
      Resize();
      data[tail] = value;
      tail = (tail + 1) % capacity;
    }
    else
    {
      data[tail] = value;
      tail += 1;
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

QueueA::T& QueueA::Top(){
  if (!IsEmpty())
  {
    return data[head];
  }
  else
  {
    throw std::out_of_range("QueueA - try get top form empty queue.");
  }
}

const QueueA::T& QueueA::Top() const
{
  if (!IsEmpty())
  {
    return data[head];
  }
  else
  {
    throw std::out_of_range("QueueA - try get top form empty queue.");
  }
}

void QueueA::Pop(){
  if (!IsEmpty())
  {
    if (size == 0)
    {
      capacity = 0;
      Resize();
    }
    else
    {
      std::ptrdiff_t old_head = head;
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
    throw std::out_of_range("QueueA - try get top form empty queue.");
  }
}