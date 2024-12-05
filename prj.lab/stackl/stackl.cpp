#include <stackl/stackl.hpp>
#include <memory>
#include <cstring>
#include <iostream>

void StackL::Push(std::uint8_t& v){
  auto nn = std::unique_ptr<Node>(new Node(v));
  nn -> next = std::move(head);
  head = std::move(nn);
}

void StackL::Pop(){
  if (head != nullptr)
  {
    head = std::move(head -> next);
  }
}

std::uint8_t& StackL::Top()
{
  if (head != nullptr)
  {
    std::uint8_t buf = head -> value;
    head = std::move(head -> next);
    return buf;
  }
  std::cout << "BRO STACK AS EMPTY AS YOUR BRAINS";
}