#include "queue.hpp"

Queue::Queue() {
    startPtr = nullptr;
}

Queue::~Queue() {
}

void Queue::enqueue(int value) {
    Node *tempPtr = startPtr;

    if (is_empty()) {
        startPtr = new Node;
        startPtr->data = value;
        startPtr->nextPtr = nullptr;

    } else {
        Node *newPtr = new Node;
        newPtr->data = value;
        newPtr->nextPtr = nullptr;

        while (tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr;
        }

        tempPtr->nextPtr = newPtr;
    }
}

void Queue::dequeue() {
    if (is_empty()) {
        std::cerr << "Dequeue(): Queue is empty!\n";
        return;
    }

    Node *nextPtr = startPtr->nextPtr;
    delete startPtr;
    startPtr = nextPtr;
}

void Queue::print() {
    if (is_empty()) {
        std::cerr << "Print(): Queue is empty!\n";
        return;
    }

    Node *tempPtr = startPtr;

    while (tempPtr != nullptr) {
        std::cout << " => " << tempPtr->data;
        tempPtr = tempPtr->nextPtr;
    }
    std::cout << " => \n";
}

bool Queue::is_empty() {
    return startPtr == nullptr;
}