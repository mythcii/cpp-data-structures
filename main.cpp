#include <iostream>
#include <string>

#include "SinglyLinkedList.h"

void testSinglyLinkedList();

int main() {
    testSinglyLinkedList();


    return 0;
}

void testSinglyLinkedList() {
    SinglyLinkedList sll;
    std::string output;

    sll.print();
    //Case 1: Empty list
    output = sll.insertAfter(0, 1) ? "1 inserted after 0\n" : "0 not found, 1 not inserted\n";
    //std::cout << output;
    output += sll.findData(1) ? "1 found\n" : "1 not found\n";
    output += sll.deleteData(2) ? "2 deleted\n" : "2 not found, thus not deleted\n";
    output += sll.deleteHead() ? "Head deleted\n" : "List empty, no head to delete\n";
    output += sll.deleteEnd() ? "End deleted\n" : "List empty, no end to delete\n";
    std::cout << output;

    //Case 2: Insert at head
    sll.insertAsHead(0);
    sll.insertAsHead(1);
    sll.print();

    //Case 3: Insert at end
    sll.insertAsEnd(2);
    sll.insertAsEnd(3);
    sll.print();

    //Case 4: Insert after specified data
    //inserting after a middle node
    output = sll.insertAfter(0, 4) ? "4 inserted after 0\n" : "0 not found, 4 not inserted\n";
    //inserting after head
    output += sll.insertAfter(1, 5) ? "5 inserted after 1\n" : "1 not found, 5 not inserted\n";
    //inserting after end
    output += sll.insertAfter(3, 6) ? "6 inserted after 3\n" : "3 not found, 6 not inserted\n";
    //inserting after non-existing data
    output += sll.insertAfter(644, 7) ? "7 inserted after 644\n" : "644 not found, 7 not inserted\n";
    std::cout << output;

    sll.print();
}