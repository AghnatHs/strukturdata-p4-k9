#pragma once

#include <iostream>

template <typename T>
class Queue {
   private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

   public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();

    void enqueue(const T& value);
    void enqueueFront(const T& value);

    T dequeue();
    T peek() const;
    bool isEmpty() const;
    int getSize() const;

    void print() const;
    void clear();
};

#include "../../src/domain/queue.ipp"