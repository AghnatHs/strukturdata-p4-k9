#pragma once

#include <stdexcept>

#include "domain/stack.hpp"
using namespace std;

template <typename T>
Stack<T>::Stack() : topNode(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(const T& item) {
    Node* newNode = new Node{item, topNode};
    topNode = newNode;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) throw std::runtime_error("Stack underflow!");
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) throw std::runtime_error("Stack is empty!");
    return topNode->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return topNode == nullptr;
}

template <typename T>
void Stack<T>::clear() {
    while (topNode) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}