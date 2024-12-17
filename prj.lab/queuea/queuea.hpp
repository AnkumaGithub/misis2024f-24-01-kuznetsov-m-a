#ifndef QUEUEA_H
#define QUEUEA_H
#include <cstring>
#include <cstdint>
#include <cstddef>


class QueueA {
  public:
    using T = std::uint8_t;
    QueueA();
    ~QueueA();

    bool IsEmpty() const;
    void Resize();

    QueueA(const QueueA& other);
    QueueA(QueueA&& other) noexcept;

    std::ptrdiff_t get_size() const;
    std::ptrdiff_t get_capacity() const;

    void show_queue();

    std::ptrdiff_t Count_size() const;

    QueueA& operator=(const QueueA& other);
    QueueA& operator=(QueueA&& other);

    void Push(const T &value);
    void Pop();

    T& Top();
    const T& Top() const;
  private:
    std::ptrdiff_t capacity = 1;
    std::ptrdiff_t size = 0;
    std::ptrdiff_t head = 0;
    std::ptrdiff_t tail = 0;
    T *data = nullptr;

    void move_head();
    void move_tail();

    void Swap(QueueA&& other) noexcept;
    bool IsEnough();
};
#endif