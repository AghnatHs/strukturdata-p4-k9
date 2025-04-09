#pragma once
#include <iostream>
#include <stdexcept>

#include "domain/queue.hpp"
using namespace std;

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Queue is empty");
    }

    Node* temp = front;
    T value = temp->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
    size--;

    return value;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw runtime_error("No data available.");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
int Queue<T>::getSize() const {
    return size;
}

template <typename T>
void Queue<T>::print() const {
    if (isEmpty()) {
        throw runtime_error("No data available.");
    }

    Node* current = front;
    cout << "[ LAMA ]\n" << endl;
    while (current != nullptr) {
        cout << "-> " << current->data << endl;
        current = current->next;
    }
    cout << "[ BARU ]" << endl;
}

template <typename T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}
