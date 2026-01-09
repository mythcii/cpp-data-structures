#include <iostream>
#include <string>

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

template<typename listType> void testList(listType* listObj);
void testSinglyLinkedList();
void testDoublyLinkedList();

int main() {
    testSinglyLinkedList();
    testDoublyLinkedList();
    
    return 0;
}

template<typename listType>
void testList(listType* listObj) {
    std::string output;

    //Case 1: Empty list
    std::cout << "EMPTY LIST OPERATIONS\n"; 
    output = listObj->insertAfter(0, 1) ? "1 inserted after 0\n" : "0 not found, 1 not inserted\n";
    output += listObj->findData(1) ? "1 found\n" : "1 not found\n";
    output += listObj->deleteData(2) ? "2 deleted\n" : "2 not found, thus not deleted\n";
    output += listObj->deleteHead() ? "Head deleted\n" : "List empty, no head to delete\n";
    output += listObj->deleteEnd() ? "End deleted\n" : "List empty, no end to delete\n";
    std::cout << output;
    listObj->print();

    //Case 2: Insert at head
    std::cout << "INSERT 0 AND 1 AT HEAD\n";
    listObj->insertAsHead(0);
    listObj->insertAsHead(1);
    listObj->print();

    //Case 3: Insert at end
    std::cout << "INSERT 2 AND 3 AT END\n";
    listObj->insertAsEnd(2);
    listObj->insertAsEnd(3);
    listObj->print();

    //Case 4: Insert after specified data
    std::cout << "INSERT X AFTER Y\n";
    //insert after a middle node
    output = listObj->insertAfter(0, 4) ? "4 inserted after 0\n" : "0 not found, 4 not inserted\n";
    //insert after head
    output += listObj->insertAfter(1, 5) ? "5 inserted after 1\n" : "1 not found, 5 not inserted\n";
    //insert after end
    output += listObj->insertAfter(3, 6) ? "6 inserted after 3\n" : "3 not found, 6 not inserted\n";
    //insert after non-existing data
    output += listObj->insertAfter(644, 7) ? "7 inserted after 644\n" : "644 not found, 7 not inserted\n";
    std::cout << output;
    listObj->print();

    //Case 5: Insert before specified data
    std::cout << "INSERT X BEFORE Y\n";
    //insert before a middle node
    output = listObj->insertBefore(0, 7) ? "7 inserted before 0\n" : "0 not found, 7 not inserted\n";
    //insert before head
    output += listObj->insertBefore(1, 8) ? "8 inserted before 1\n" : "1 not found, 8 not inserted\n";
    //insert before end
    output += listObj->insertBefore(6, 9) ? "9 inserted before 6\n" : "6 not found, 9 not inserted\n";
    //insert before non-existing data
    output += listObj->insertBefore(644, 10) ? "10 inserted before 644\n" : "644 not found, 10 not inserted\n";
    std::cout << output;
    listObj->print();

    //Case 6: Deletetions
    std::cout << "DELETIONS\n";
    //delete existing data
    output = listObj->deleteData(0) ? "0 deleted\n" : "0 not found, thus not deleted\n";
    //delete non-existing data
    output += listObj->deleteData(644) ? "644 deleted\n" : "644 not found, thus not deleted\n";
    //delete head
    output += listObj->deleteHead() ? "Head deleted\n" : "List empty, no head to delete\n";
    //delete end
    output += listObj->deleteEnd() ? "End deleted\n" : "List empty, no end to delete\n";
    std::cout << output;
    listObj->print();

    //Case 7: Clear and inserting at end to empty list
    std::cout << "LIST CLEARED\n";
    listObj->clear();
    listObj->print();
    std::cout << "INSERT 0 AT END INTO EMPTY LIST\n";
    listObj->insertAsEnd(0);
    listObj->print();

    //Case 8: Delete end/head with only one node
    std::cout << "HEAD/END DELETIONS WITH ONLY ONE NODE IN LIST\n";
    listObj->deleteHead() ? std::cout << "Head deleted\n" : std::cout << "List empty, no head to delete\n";
    listObj->print();

    std::cout << "Reinserting 0\n";
    listObj->insertAsHead(0);
    listObj->print();

    listObj->deleteEnd() ? std::cout << "End deleted\n" : std::cout << "List empty, no end to delete\n";
    listObj->print();

    std::cout << "------------------------------------------------------\n";
}

void testSinglyLinkedList() {
    SinglyLinkedList sll;
    std::cout << "TESTING SINGLY LINKED LIST\n\n";
    testList(&sll);
}

void testDoublyLinkedList() {
    DoublyLinkedList dll;
    std::cout << "TESTING DOUBLY LINKED LIST\n\n";
    testList(&dll);
}
