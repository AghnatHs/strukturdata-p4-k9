#pragma once

template <typename T>
class Stack {
   private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode;

   public:
    Stack();
    ~Stack();

    void push(const T& item);
    void pop();
    T top() const;
    bool isEmpty() const;

    void clear();
};

#include "../../src/domain/stack.ipp"