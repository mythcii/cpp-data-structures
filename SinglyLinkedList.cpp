#include "SinglyLinkedList.h"
#include <iostream>

//destructor
SinglyLinkedList::~SinglyLinkedList() {
    //deletes heads until list is empty
    clear();
}

//insert at beginning
void SinglyLinkedList::insertAsHead(const int data) {
    //initialize new node
    Node* newNode = new Node(data);

    //new node points to the current head
    newNode->next = head;

    //new node becomes the current head
    head = newNode;
}
    
//insert at end
void SinglyLinkedList::insertAsEnd(const int data) {
    //initialize new node
    Node* newNode = new Node(data);

    //list is empty, so set new node as head
    if (!head) head = newNode;
    //iterates until end node is reached
    else {
        Node* currentNode = head;
        while (currentNode) {
            if (!currentNode->next) {
                currentNode->next = newNode;
                return;
            }
            currentNode = currentNode->next;
        }
    }

}

//insert after preceding data
bool SinglyLinkedList::insertAfter(const int precedingData, const int insertData) {
    //Node* that matches preceding data
    Node* precedingNode = findNode(precedingData);

    //could not find node with matching preceding data, therefore can't insert
    if (!precedingNode) return false;
    
    //initialize new node
    Node* newNode = new Node(insertData);

    //new node points to subsequent node
    newNode->next = precedingNode->next;

    //preceding node points to new node
    precedingNode->next = newNode;

    return true;
}

 //insert before subsequent data
bool SinglyLinkedList::insertBefore(const int subsequentData, const int insertData) {
    //empty list
    if (!head) return false;

    //new node comes before the head
    if (head->data == subsequentData) {
        insertAsHead(insertData);
        return true;
    }

    //iterates until subsequent node is found
    Node* currentNode = head;
    while (currentNode->next) {
        if (currentNode->next->data == subsequentData) {
            //initialize new node
            Node* newNode = new Node(insertData);
            //new node points to subsequent node
            newNode->next = currentNode->next;
            //left neighbor points to new node
            currentNode->next = newNode;
            
            return true;
        }

        currentNode = currentNode->next;
    }

    //no match for subsequent data
    return false;
}

//find node that matches specified data 
SinglyLinkedList::Node* SinglyLinkedList::findNode(const int data) {
    //iterates until a match is reached
    Node* currentNode = head;
    while (currentNode) {
        if (currentNode->data == data) return currentNode;
        currentNode = currentNode->next;
    }

    //returns nullptr (no match found)
    return currentNode;
}

//find if data exists in list
bool SinglyLinkedList::findData(const int data) {
    if (findNode(data)) return true;
    return false;
}

//delete specified data
bool SinglyLinkedList::deleteData(const int data) {
    //list is empty, no data to delete
    if (!head) return false;
    
    //iterates until the next node is a match
    Node* currentNode = head; 
    while (currentNode->next) {
        if (currentNode->next->data == data) {
            //temp Node* to be deleted
            Node* deleteNode = currentNode->next;
            //redirect current node to point to next, next node
            currentNode->next = deleteNode->next;
            //finally delete specified node
            delete deleteNode;
            return true;
        }

        currentNode = currentNode->next;
    }

    //no match
    return false;
}

//delete beginning
bool SinglyLinkedList::deleteHead() {
    //list is empty, no deletion necessary
    if (!head) return false;

    //temp Node* to store current head's address
    Node* tempHead = head;
    //second node in list becomes head
    head = tempHead->next;
    //finally delete old head
    delete tempHead;

    return true;
}

//delete end
bool SinglyLinkedList::deleteEnd() {
    //list is empty, no deletion necessary
    if (!head) return false;

    //iterates until end is reached
    Node* currentNode = head;
    while (currentNode->next) {
        if (!currentNode->next->next) {
            //delete end
            delete currentNode->next;
            //new end points to nullptr
            currentNode->next = nullptr;
            return true;
        }

        currentNode = currentNode->next;
    }

    //there is only head
    delete currentNode;
    head = nullptr;
    return true;
}

//print to terminal
void SinglyLinkedList::print(bool nullptrVisibility) {
    std::cout << "SLL: ";

    //no data to print
    if (!head) {
        std::cout << "list is empty\n" << std::endl;
        return;
    }

    //iterates until end is reached
    Node* currentNode = head;
    if (nullptrVisibility) {
        while (currentNode) {
            std::cout << currentNode->data << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << "nullptr\n\n";
    }
    else {
        while (currentNode) {
            std::cout << currentNode->data;
            currentNode->next ? std::cout << " -> " : std::cout << "\n\n";
            currentNode = currentNode->next;
        }
    }
}

//resets list
void SinglyLinkedList::clear() {
    //deletes heads until list is empty
    while (head) {
        deleteHead();
    }
}