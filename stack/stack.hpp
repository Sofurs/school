#pragma once

#define SIZE 500

class Stack {
   public:
    Stack();
    ~Stack();

    void push(int num);
    int pop();
    int peek();
    bool is_empty();

   private:
    int stack[SIZE];
    int top = -1;
};