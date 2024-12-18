#pragma once
#ifndef STACKL_H
#define STACKL_H
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <memory>

class StackL{
public:
    using T = std::uint8_t;
    StackL(): head(nullptr){}
    ~StackL() = default;

    void Push(T v);
    void Pop();

    StackL(const StackL& other);
    StackL(StackL&& other) noexcept;

    [[nodiscard]] T& Top() &;
    [[nodiscard]] const T& Top() const &;
    StackL& operator=(const StackL& other);
    StackL& operator=(StackL&& other) noexcept;
    void Clear() noexcept;
    bool IsEmpty() const noexcept;
private:
    struct Node{
        std::unique_ptr<Node> next;
        T value;
        Node(T& v): value(v), next(nullptr){}
    };
    std::unique_ptr<Node> head;
};
#endif //STACKL_H