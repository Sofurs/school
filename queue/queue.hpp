#pragma once

#include <iostream>

struct node {
    int data;
    struct node *nextPtr;
};

typedef struct node Node;

class Queue {
   public:
    Queue();
    ~Queue();

    void enqueue(int n);
    void dequeue();
    void print();
    bool is_empty();

   private:
    Node *startPtr;
};