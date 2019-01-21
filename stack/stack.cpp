#include "stack.hpp"

#include <iostream>

Stack::Stack() {
}

Stack::~Stack() {
}

void Stack::push(int num) {
    if (top < SIZE - 1) {
        stack[++top] = num;
    } else {
        std::cerr << "Maximum stack size reached!\n";
    }
}

int Stack::pop() {
    if (top > -1) {
        int topNum = stack[top];
        stack[top] = 0;
        top--;
        return topNum;
    } else {
        std::cerr << "Nothing to pop!\n";
        return -1;
    }
}

int Stack::peek() {
    return stack[top];
}

bool Stack::is_empty() {
    if (!(top + 1)) {
        return true;
    } else {
        return false;
    }
}
