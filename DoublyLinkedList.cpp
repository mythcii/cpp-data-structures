#include "DoublyLinkedList.h"
#include <iostream>

//destructor
DoublyLinkedList::~DoublyLinkedList() {
    //deletes heads until list is empty
    while (head) {
        deleteHead();
    }
}

//insert at beginning
void DoublyLinkedList::insertAsHead(const int data) {
    //initialize new node
    Node* newNode = new Node(data);
    
    //new node points towards current head
    newNode->next = head;

    //head's previous node becomes new node if head exists (not nullptr)
    if (head) head->previous = newNode;

    //new node becomes head
    head = newNode;
}

//insert at end
void insertAsEnd(const int data) {
    Node* newNode = new Node(data);

    //list is empty, so node becomes the head
    if (!head) head = newNode;
    //iterates until end node is reached
    else {
        while (currentNode) {
            if (!currentNode->next) {
                //link bidirectionally
                currentNode->next = newNode;
                newNode->previous = currentNode;
                return;
            }
            currentNode = currentNode->next;
        }
    }
}

//insert after preceding data
bool DoublyLinkedList::insertAfter(const int precedingData, const int insertData) {
    //Node* that matches preceding data
    Node* precedingNode = findNode(precedingData);

    //could not find node with matching preceding data, therefore cannot insert
    if (!precedingNode) return false;

    //initialize new node
    Node* newNode = new Node(insertData);

    //link new node to neighboring nodes
    newNode->previous = precedingNode;
    newNode->next = precedingNode->next;

    //preceding node points to new node
    precedingNode->next = newNode;
}

//insert before subsequent data
bool DoublyLinkedList::insertBefore(const int subsequentData, const int insertData) {
    //Node* that matches preceding data
    Node* subsequentNode = findNode(subsequentData);

    //could not find node with matching preceding data, therefore cannot insert
    if (!subsequentNode) return false;

    //initialize new node
    Node* newNode = new Node(insertData);

    //link new node to neighboring nodes
    newNode->previous = subsequentNode->previous;
    newNode->next = subsequentNode;

    //subsequent node's previous becomes new node
    subsequentNode->previous = newNode;
}

//find node that matches specified data 
DoublyLinkedList::Node* DoublyLinkedList::findNode(const int data) { 
    //iterates until match is found
    Node* currentNode = head;
    while (currentNode) {
        if (currentNode->data == data) return currentNode;
        currentNode = currentNode->next;
    }

    //returns nullptr (no match found)
    return currentNode;
}

//find if data exists in list
bool DoublyLinkedList::findData(const int data) {
    if (findNode(data)) return true;
    return false;
}

//delete specified data
bool DoublyLinkedList::deleteData(const int data) {
    //Node to be deleted
    Node* deleteNode = findNode(data);

    //no match found so no deletion
    if (!deleteNode) return false;

    //link the node to be deleted's neighbors together
    //if the to be deleted node is NOT the head
    if (deleteNode->previous) {
        deleteNode->previous->next = deleteNode->next;
    }
    //if the to be deleted node is NOT the head nor end
    if (deleteNode->next) {
        deleteNode->next->previous = deleteNode->previous;
    }

    //finally delete specified node
    delete deleteNode;
    return true;
}

//delete beginning
bool DoublyLinkedList::deleteHead() {
    //case 1: list is empty, no deletion necessary
    if (!head) return false;

    //case 2: there is a node after head
    if (head->next) {
        //temp Node* to store current head's address
        Node* tempHead = head;
        //set up second node to become head
        head->next->previous = nullptr;
        //officially assign second node to be head
        head = head->next;
        //finally delete old head
        delete tempHead;
    }
    //case 3: there is only head
    else {
        //becomes empty list
        delete head;
        head = nullptr;
    }

    return true;
}

//delete end
bool DoublyLinkedList::deleteEnd() {
    //list is empty, no deletion necessary
    if (!head) return false;

    //iterates until end node is reached
    Node* currentNode = head;
    while (currentNode->next) {
        if (!currentNode->next->next) {
            delete currentNode->next;
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

//prints list to terminal
void DoublyLinkedList::print() {

}