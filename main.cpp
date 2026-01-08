#include <iostream>
#include <string>

#include "SinglyLinkedList.h"
//#include "DoublyLinkedList.h"

void testSinglyLinkedList();

int main() {
    testSinglyLinkedList();


    return 0;
}

void testSinglyLinkedList() {
    SinglyLinkedList sll;
    std::string output;

    //Case 1: Empty list
    std::cout << "EMPTY LIST OPERATIONS\n"; 
    output = sll.insertAfter(0, 1) ? "1 inserted after 0\n" : "0 not found, 1 not inserted\n";
    output += sll.findData(1) ? "1 found\n" : "1 not found\n";
    output += sll.deleteData(2) ? "2 deleted\n" : "2 not found, thus not deleted\n";
    output += sll.deleteHead() ? "Head deleted\n" : "List empty, no head to delete\n";
    output += sll.deleteEnd() ? "End deleted\n" : "List empty, no end to delete\n";
    std::cout << output;
    sll.print();

    //Case 2: Insert at head
    std::cout << "INSERT 0 AND 1 AT HEAD\n";
    sll.insertAsHead(0);
    sll.insertAsHead(1);
    sll.print();

    //Case 3: Insert at end
    std::cout << "INSERT 2 AND 3 AT END\n";
    sll.insertAsEnd(2);
    sll.insertAsEnd(3);
    sll.print();

    //Case 4: Insert after specified data
    std::cout << "INSERT X AFTER Y\n";
    //insert after a middle node
    output = sll.insertAfter(0, 4) ? "4 inserted after 0\n" : "0 not found, 4 not inserted\n";
    //insert after head
    output += sll.insertAfter(1, 5) ? "5 inserted after 1\n" : "1 not found, 5 not inserted\n";
    //insert after end
    output += sll.insertAfter(3, 6) ? "6 inserted after 3\n" : "3 not found, 6 not inserted\n";
    //insert after non-existing data
    output += sll.insertAfter(644, 7) ? "7 inserted after 644\n" : "644 not found, 7 not inserted\n";
    std::cout << output;
    sll.print();

    //Case 5: Insert before specified data
    std::cout << "INSERT X BEFORE Y\n";
    //insert before a middle node
    output = sll.insertBefore(0, 7) ? "7 inserted before 0\n" : "0 not found, 7 not inserted\n";
    //insert before head
    output += sll.insertBefore(1, 8) ? "8 inserted before 1\n" : "1 not found, 8 not inserted\n";
    //insert before end
    output += sll.insertBefore(6, 9) ? "9 inserted before 6\n" : "6 not found, 9 not inserted\n";
    //insert before non-existing data
    output += sll.insertBefore(644, 10) ? "10 inserted before 644\n" : "644 not found, 10 not inserted\n";
    std::cout << output;
    sll.print();

    //Case 6: Deletetions
    std::cout << "DELETIONS\n";
    //delete existing data
    output = sll.deleteData(0) ? "0 deleted\n" : "0 not found, thus not deleted\n";
    //delete non-existing data
    output += sll.deleteData(644) ? "644 deleted\n" : "644 not found, thus not deleted\n";
    //delete head
    output += sll.deleteHead() ? "Head deleted\n" : "List empty, no head to delete\n";
    //delete end
    output += sll.deleteEnd() ? "End deleted\n" : "List empty, no end to delete\n";
    std::cout << output;
    sll.print();

    //Case 7: Clear and inserting at end to empty list
    std::cout << "LIST CLEARED\n";
    sll.clear();
    sll.print();
    std::cout << "INSERT 0 AT END INTO EMPTY LIST\n";
    sll.insertAsEnd(0);
    sll.print();

    //Case 8: Delete end/head with only one node
    std::cout << "HEAD/END DELETIONS WITH ONLY ONE NODE IN LIST\n";
    sll.deleteHead() ? std::cout << "Head deleted\n" : std::cout << "List empty, no head to delete\n";
    sll.print();

    std::cout << "Reinserting 0\n";
    sll.insertAsHead(0);
    sll.print();

    sll.deleteEnd() ? std::cout << "End deleted\n" : std::cout << "List empty, no end to delete\n";
    sll.print();
}