#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
    public:
        
        LinkedList(int data);
        LinkedList(LinkedList *ptr_child, int data);

        ~LinkedList() = default;

        LinkedList *ptr_child_;
    
        friend void print_data(LinkedList* ptr);
    
    private:
        int data_;
};

#endif