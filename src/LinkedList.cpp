#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(int data)
{
    cout << "\033[1;31m(LinkedList) Constructor 1, setting pointer to NULL by default\033[0m" << endl;
    data_ = data;
}

LinkedList::LinkedList(LinkedList *ptr_child, int data)
{
    cout << "\033[1;32m(LinkedList)Constructor 2, setting pointer to a child node\033[0m" << endl;
    ptr_child_ = ptr_child;
    data_ = data;
}

int LinkedList::getData()
{
    return data_;
}

// Friend function, so it can access to private data
void print_data(LinkedList* ptr)
{
    std::cout << ptr->data_;
}