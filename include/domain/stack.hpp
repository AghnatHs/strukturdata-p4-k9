#pragma once

#include "domain/letter.hpp"

template <typename T>
class Stack {
   protected:
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
    void print();
};

#include "../../src/domain/stack.ipp"