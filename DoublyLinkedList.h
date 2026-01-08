#ifndef Doubly_Linked_List_H
#define Doubly_Linked_List_H

class DoublyLinkedList {
    private:
    //Nodes comprise the list
    struct Node {
        //holds int data
        int data;

        //points to next node
        Node* next;

        //points to previous node
        Node* previous;

        //constructor
        Node(int data) : data(data), next(nullptr), previous(nullptr) {};
    }

    //head of list
    Node* head;

    public:
    //constructor
    DoublyLinkedList() : head(nullptr) {};

    //destructor
    ~DoublyLinkedList();

    //insert at beginning
    void insertAsHead(const int data);
    
    //insert at end
    void insertAsEnd(const int data);

    //insert after preceding data
    bool insertAfter(const int precedingData, const int insertData);

    //insert before subsequent data
    bool insertBefore(const int subsequentData, const int insertData);

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