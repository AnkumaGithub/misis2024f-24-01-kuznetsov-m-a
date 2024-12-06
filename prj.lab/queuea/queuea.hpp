#ifndef QUEUEA_H
#define QUEUEA_H
#include <cstring>
#include <cstdint>
#include <cstddef>


class QueueA {
  private:
    ptrdiff_t capacity = 1;
    ptrdiff_t size = 0;
    ptrdiff_t head = 0;
    ptrdiff_t tail = 0;
    std::uint8_t *data = nullptr;

  public:
    QueueA();
    ~QueueA() = default;

    ptrdiff_t get_size() const;
    ptrdiff_t get_capacity() const;
    bool IsEmpty() const;

    void show_queue();
    void move_head();
    void move_tail();
    bool IsEnough();
    void Resize();

    void Push(std::uint8_t &value);
    void Pop();

    std::uint8_t& Top();
};
#endif