#include <iostream>
#include "LinkedList.hpp"

#include <set>

using namespace std;

int main()
{
    cout << endl << "Linked List Example:" << endl;
    cout << "--------------------" << endl << endl;

    // Create List
    cout << endl << "1. Creating a list and priting it using only the head of the list: " << endl;
    LinkedList* obj_first = new LinkedList(10);
    LinkedList* obj_second = new LinkedList(20);
    obj_first->ptr_child_ = obj_second;
    LinkedList* obj_third = new LinkedList(30);
    obj_second->ptr_child_ = obj_third;

    // Print it using only the head of the list
    cout << "First:  ";  print_data(obj_first);                         cout << endl;
    cout << "Second: "; print_data(obj_first->ptr_child_);             cout << endl;
    cout << "Third:  ";  print_data(obj_first->ptr_child_->ptr_child_); cout << endl;

    // Print list iterating
    cout << endl << "2. Going through the list using the pointer to the childs" << endl;
    LinkedList* iter = obj_first;
    while(iter != NULL)
    {
        cout << "Iter content: "; print_data(iter); cout << endl;
        iter = iter->ptr_child_;
    }

    // Add a last and an intermediate element to the list
    cout << endl << "Adding intermediate element: " << endl;
    LinkedList* obj_last = new LinkedList(50);
    LinkedList* obj_fourth = new LinkedList(obj_last, 40);
    obj_third->ptr_child_ = obj_fourth;

    // Print list iterating again
    iter = obj_first;
    while(iter != NULL)
    {
        cout << "Iter content: "; print_data(iter); cout << endl;
        iter = iter->ptr_child_;
    }

    // Note: Do you know that any class has a default copy constructor, right?:
    cout << endl << "3. Creating a copy of the head of the list: " << endl;
    LinkedList copied_list(*obj_first);

    // Print list using the copy of the head of the list
    cout << "Copied element:       "; print_data(&copied_list);                       cout << endl;
    cout << "Child of the copy:    "; print_data(copied_list.ptr_child_);             cout << endl;
    cout << "The following elemnt: "; print_data(copied_list.ptr_child_->ptr_child_); cout << endl;
    return 0;
}