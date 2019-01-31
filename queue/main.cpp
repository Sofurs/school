#include <iostream>

#include "queue.hpp"

int main() {
    Queue queue;

    char choice;

    std::cout << "Enter 'e' for enqueue, 'd' for dequeue, 'p' for print, 'q' for Quit\n";

    while (choice != 'q') {
        std::cout << "\nEnter operation: ";
        std::cin >> choice;
        tolower(choice);

        switch (choice) {
            case 'e':
                int num;
                std::cout << "Enter num: ";
                std::cin >> num;
                queue.enqueue(num);
                queue.print();
                break;
            case 'd':
                queue.dequeue();
                queue.print();
                break;
            case 'p':
                queue.print();
                break;
            default:
                std::cerr << "Wrong input! Try again.\n";
                break;
        }
    }
}