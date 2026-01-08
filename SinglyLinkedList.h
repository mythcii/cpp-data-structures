//prevent multiple definitions
#ifndef Singly_Linked_List_H_
#define Singly_Linked_List_H_

class SinglyLinkedList {
private:
    //Nodes comprise the list
    struct Node {
    //holds int data
    int data;

    //points to next Node
    Node* next;

    //constructor
    Node(int data) : data(data), next(nullptr) {}
};

    //head of the list
    Node* head;

public:
    //constructor
    SinglyLinkedList() : head(nullptr) {};

    //destructor
    ~SinglyLinkedList();

    //insert at beginning
    void insertAsHead(const int data);
    
    //insert at end
    void insertAsEnd(const int data);

    //insert after preceding data
    bool insertAfter(const int precedingData, const int insertData);

    //find node that matches specified data 
    Node* findNode(const int data);

    //find if data exists in list
    bool findData(const int data);

    //delete specified data
    bool deleteData(const int data);

    //delete beginning
    bool deleteHead();

    //delete end
    bool deleteEnd();

    //prints list to terminal
    void print();
};

#endif