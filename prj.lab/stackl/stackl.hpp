#ifndef STACKL_H
#define STACKL_H
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <memory>

struct StackL{
  private:
    struct Node{
      std::unique_ptr<Node> next;
      std::uint8_t value;

      Node(std::uint8_t& v): value(v), next(nullptr){}
    };
    std::unique_ptr<Node> head;
   public:
     StackL(): head(nullptr){}
     ~StackL() = default;

     void Push(std::uint8_t& v);
     void Pop();
     std::uint8_t& Top();
};
#endif