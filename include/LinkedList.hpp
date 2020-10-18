#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
    public:
        
        // Constructors
        LinkedList(int data);
        LinkedList(LinkedList *ptr_child, int data);

        // Destructor
        ~LinkedList() = default;

        // Pointer to the next element
        LinkedList *ptr_child_ {NULL};

        // Get this element data
        int getData();

        // Print this element data
        friend void print_data(LinkedList* ptr);
        
    private:
        int data_;
};

#endif