#include <memory>
#include <stackl/stackl.hpp>
#include <memory>
#include <cstring>
#include <stdexcept>
#include <iostream>

void StackL::Push(T& v){
  auto nn = std::make_unique<Node>(v);
  nn -> next = std::move(head);
  head = std::move(nn);
}

void StackL::Pop(){
  if (head != nullptr)
  {
    head = std::move(head -> next);
  }
}

StackL::T& StackL::Top() &{
  if (!IsEmpty())
  {
    T& buf = head -> value;
    return buf;
  }
  throw std::logic_error("StackL - try get top form empty stack.");
}

const StackL::T& StackL::Top() const&
{
  if (!IsEmpty())
  {
    const T& buf = head -> value;
    return buf;
  }
  throw std::logic_error("StackL - try get top form empty stack.");
}

StackL::StackL(const StackL& other)
{
  Clear();
  auto nn = std::make_unique<Node>(other.head -> value);
  nn -> next = std::move(head);
  head = std::move(nn);
  while(head -> next)
  {
    head -> next = std::make_unique<Node>(head -> next -> value);
    nn -> next = std::move(head);
    head = std::move(nn);
  }
}

StackL& StackL::operator=(StackL&& other) noexcept {
  std::swap(head, other.head);
  return *this;
}

StackL& StackL::operator=(const StackL& other)
{
  if (this != &other)
  {
    Clear();
    auto nn = std::make_unique<Node>(other.head -> value);
    nn -> next = std::move(head);
    head = std::move(nn);
    while(head -> next)
    {
      head -> next = std::make_unique<Node>(head -> next -> value);
      nn -> next = std::move(head);
      head = std::move(nn);
    }
  }
  return *this;
}

bool StackL::IsEmpty() const noexcept{ return head == nullptr;}


void StackL::Clear() noexcept
{
  while(!IsEmpty())
  {
    Pop();
  }
}