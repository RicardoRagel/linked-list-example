#include <iostream>
#include <stdio.h>
#include <set>

#include "LinkedList.hpp"
#include "WhiteBoard.hpp"

using namespace std;

// Draw a LinkedList on the WhiteBoard
void draw_list(LinkedList* iter, WhiteBoard* board)
{
    // Go through the list until the last element
    int column_index = 1;
    while(iter != NULL)
    {
        cout << "Iter content: "; print_data(iter); cout << endl;
        
        // Draw element
        int node_x = board->getW() * column_index/10;        // Column by column of the whiteboard
        int node_y = board->getH() * iter->getData() / 100;  // As low as the data value (~ height percentage)
        board->drawNode(node_x, node_y);
        board->drawTag(node_x + 10, node_y, to_string(iter->getData()));

        // Draw the arrow to its child
        if(iter->ptr_child_ != NULL)
        {
            int child_node_x = board->getW() * (column_index + 1)/10;
            int child_node_y = board->getH() * iter->ptr_child_->getData() / 100;
            board->drawArrow(node_x, node_y, child_node_x, child_node_y);
        }
        
        // Next element
        iter = iter->ptr_child_;
        column_index++;
    }
}

int main()
{
    cout << endl;
    cout << "Linked List Example:" << endl;
    cout << "--------------------" << endl;

    /* 
        Create a List
    */
    cout << endl << "1. Creating a list and priting it using only the head of the list: " << endl;
    LinkedList* obj_first = new LinkedList(10);
    LinkedList* obj_second = new LinkedList(30);
    obj_first->ptr_child_ = obj_second;
    LinkedList* obj_third = new LinkedList(60);
    obj_second->ptr_child_ = obj_third;

    // Print it using only the head of the list
    cout << "First:  "; print_data(obj_first);                         cout << endl;
    cout << "Second: "; print_data(obj_first->ptr_child_);             cout << endl;
    cout << "Third:  "; print_data(obj_first->ptr_child_->ptr_child_); cout << endl;

    /*
        Go through the list using the child pointers and draw it
    */
    cout << endl << "2. Going through the list using the pointer to the childs and drawing it" << endl;    
    LinkedList* iter = obj_first;
    
    // Create white-board window 640x480
    WhiteBoard board;
    board.open(640, 480);
    
    // Draw it
    draw_list(iter, &board);

    cout << endl << "Press Any Key To Continue...";
    getchar();

    /* 
        Add a last and an intermediate element to the list
    */
    cout << endl << " 3. Adding more element: " << endl;
    LinkedList* obj_last = new LinkedList(80);
    LinkedList* obj_fourth = new LinkedList(obj_last, 40);
    obj_third->ptr_child_ = obj_fourth;

    // Draw the list
    draw_list(iter, &board);

    // Note: Do you know that any class has a default copy constructor, right?:
    // cout << endl << "3. Creating a copy of the head of the list: " << endl;
    // LinkedList copied_list(*obj_first);

    // // Print list using the copy of the head of the list
    // cout << "Copied element:       "; print_data(&copied_list);                       cout << endl;
    // cout << "Child of the copy:    "; print_data(copied_list.ptr_child_);             cout << endl;
    // cout << "The following elemnt: "; print_data(copied_list.ptr_child_->ptr_child_); cout << endl;

    cout << endl << "Press Any Key To Exit...";
    getchar();

    return 0;
}