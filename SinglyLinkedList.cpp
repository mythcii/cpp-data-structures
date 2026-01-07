#include "SinglyLinkedList.h"

//destructor
~SinglyLinkedList() {
    //deletes heads until list is empty
    while (head) {
        deleteHead();
    }
}

//insert at beginning
void insertAsHead(const int data) {
    //initialize new node
    Node* newNode = new Node(data);

    //new node points to the current head
    newNode->next = head;

    //new node becomes the current head
    head = newNode;
}
    
//insert at end
void insertAsEnd(const int data) {
    //initialize new node
    Node* newNode = new Node(data);

    //list is empty, so set new node as head
    if (!head) head = newNode;
    //iterates until end node is reached
    else {
        Node* currentNode = head;
        while (currentNode) {
            if (!currentNode->next) currentNode->next = newNode;
            else currentNode = currentNode->next;
        }
    }

}

//insert after preceding data
bool insertAfter(const int precedingData, const int insertData) {
    //Node* that matches preceding data
    Node* precedingNode = findData(precedingData);

    //could not find node with matching preceding data, therefore can't insert
    if (precedingNode) return false;

    //initialize new node
    Node* newNode = new Node(data);

    //new node points to subsequent node
    newNode->next = precedingNode->next;

    //preceding node points to new node
    precedingNode->next = newNode;

    return true;
}

//find node that matches specified data 
Node* findNode(const int data) {
    //list is empty, no data
    if (!head) return nullptr;

    //iterates until a match is found
    Node* currentNode = head;
    while (currentNode) {
        if (currentNode->data == data) return currentNode;
        currentNode = currentNode->next;
    }

    //returns Node* that matches data
    return currentNode;
}

//find if data exists in list
bool findData(const in data) {
    if (findNode(data)) return true;
    return false;
}

//delete specified data
bool deleteData(const int data) {
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

    //data could not be found
    return false;
}

//delete beginning
void deleteHead() {
    //temp Node* to be deleted
    Node* tempHead = head;
    //second node in list becomes head
    head = tempHead->next;
    //finally delete head
    delete tempHead;
}

//delete end
void deleteEnd() {
    //iterates until end is reached
    Node* currentNode = head;
    while (currentNode) {
        if (!currentNode->next) delete currentNode;
        else currentNode = currentNode->next;
    }
}

//print to terminal
void print() {
    std::cout << "SLL: ";
    //list is empty, no data to print
    if (!head) {
        std::cout << "list is empty" << std::endl;
        return;
    }

    //iterates until end is reached
    Node* currentNode = head;
    while (currentNode) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}