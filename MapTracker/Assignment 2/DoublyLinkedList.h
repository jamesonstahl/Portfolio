#pragma once
#include "DoublyLinkedListException.h"

template < class T >
class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAtFront(const T& elem);
    void insertAtRear(const T& elem);
    bool removeFromFront(T& elem);
    bool removeFromRear(T& elem);
    bool remove();
    bool remove(const T& elem);
    int size();
    bool first(T& elem);
    bool last(T& elem);
    bool next(T& elem);
    bool previous(T& elem);
    bool isEmpty();
    bool find(const T& elem);
    T& at(int pos);
    T& operator[](int pos);
    
private:
    struct Node
    {
        T data;
        Node* p_next;
        Node* p_prev;
    };

    Node* p_head;
    Node* p_tail;
    Node* p_current;
    int numberOfNodes;
};

//Constructor that creates a doubly linked list with no elements by
//setting all data members to NULL
template < class T >
DoublyLinkedList<T>::DoublyLinkedList(){
    p_head = 0;
    p_tail = 0;
    p_current = 0;
    numberOfNodes = 0;
}

//Destructor that deletes each node from the stack until the doubly
//linked list is empty
template < class T >
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(!isEmpty())
    {
        Node* p_delete = p_head;
        p_head = p_head->p_next;
        delete p_delete;
        numberOfNodes--;
    }
}

//Inserts a value at the front of the doubly linked list by setting
//the head pointer to point at this new node and connecting the new
//node and the next node if the container is not empty
template < class T >
void DoublyLinkedList<T>::insertAtFront(const T& elem){
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    if(isEmpty()){
        p_newNode->p_next = 0;
        p_newNode->p_prev = 0;
        p_head = p_newNode;
        p_tail = p_newNode;
    }
    else{
        p_newNode->p_next = p_head;
        p_newNode->p_prev = 0;
        p_head->p_prev = p_newNode;
        p_head = p_newNode;
    }
    numberOfNodes++;
}

//Inserts a value at the rear of the doubly linked list by setting
//the tail pointer to point at this new node and connecting the new
//node and the previous node if the container is not empty
template < class T >
void DoublyLinkedList<T>::insertAtRear(const T& elem){
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    if(isEmpty()){
        p_newNode->p_next = 0;
        p_newNode->p_prev = 0;
        p_head = p_newNode;
        p_tail = p_newNode;
    }
    else{
        p_newNode->p_next = 0;
        p_newNode->p_prev = p_tail;
        p_tail->p_next = p_newNode;
        p_tail = p_newNode;
    }
    numberOfNodes++;
}

//Returns true if an item is removed, elem holds that value.
//Deletes front node and sets the head pointer to point at the
//next node if the container is not empty
template < class T >
bool DoublyLinkedList<T>::removeFromFront(T& elem){
    bool retval = false;
    if(!isEmpty()){
        retval = true;
        elem = p_head->data;
        if(size() == 1){
            delete p_head;
            p_head = 0;
            p_tail = 0;
        }
        else{
            Node* p_delete = p_head;
            p_head = p_head->p_next;
            p_head->p_prev = 0;
            delete p_delete;
        }
        numberOfNodes--;
    }
    return retval;
}

//Returns true if an item is removed, elem holds that value.
//Deletes rear node and sets the tail pointer to point at the
//previous node if the container is not empty
template < class T >
bool DoublyLinkedList<T>::removeFromRear(T& elem){
    bool retval = false;
    if(!isEmpty()){
        retval = true;
        elem = p_tail->data;
        if(size() == 1){
            delete p_head;
            p_head = 0;
            p_tail = 0;
        }
        else{
            Node* p_delete = p_tail;
            p_tail = p_tail->p_prev;
            p_tail->p_next = 0;
            delete p_delete;
        }
        numberOfNodes--;
    }
    return retval;
}

//Removes the element that the current pointer points to
//and connects the appropriate nodes
template < class T >
bool DoublyLinkedList<T>::remove(){
    bool retval = false;
    if(!isEmpty() && p_current != 0){
        retval = true;
        if(p_current == p_head && p_current == p_tail){
            T data;
            removeFromFront(data);
        }
        else if(p_current == p_head){
            T data;
            removeFromFront(data);
        }
        else if(p_current == p_tail){
            T data;
            removeFromRear(data);
        }
        else{
            Node* p_delete = p_current;
            p_current->p_prev->p_next = p_current->p_next;
            p_current->p_next->p_prev = p_current->p_prev;
            p_current = p_current->p_prev;
            delete p_delete;
            numberOfNodes--;
        }
    }
    return retval;
}

//Removes all occurrences of the element that is passed in.
template < class T >
bool DoublyLinkedList<T>::remove(const T& elem){
    bool retval = false;
    for(int i = 0; i < numberOfNodes; i++){
        if(find(elem)){
            remove();
            retval = true;
        }
    }
    return retval;
}

//Returns the number of nodes being used
template < class T >
int DoublyLinkedList<T>::size(){
    return numberOfNodes;
}

//Places the current pointer at the first element
template < class T >
bool DoublyLinkedList<T>::first(T& elem){
    bool retVal = false;
    if(!isEmpty())
    {
        retVal = true;
        elem = p_head->data;
        p_current = p_head;
    }
    return retVal;
}

//Places the current pointer at the last element
template < class T >
bool DoublyLinkedList<T>::last(T& elem){
    bool retVal = false;
    if(!isEmpty())
    {
        retVal = true;
        elem = p_tail->data;
        p_current = p_tail;
    }
    return retVal;
}

//Places the current pointer at the next element
template < class T >
bool DoublyLinkedList<T>::next(T& elem){
    bool retVal = false;
    if(p_current && p_current->p_next != 0)
    {
        retVal = true;
        p_current = p_current->p_next;
        elem = p_current->data;
    }
    return retVal;
}

//Places the current pointer at the previous element
template < class T >
bool DoublyLinkedList<T>::previous(T& elem){
    bool retVal = false;
    if(p_current && p_current->p_prev != 0)
    {
        retVal = true;
        p_current = p_current->p_prev;
        elem = p_current->data;
    }
    return retVal;
}

//Returns the logical value if the number of nodes being used is 0 or not
template < class T >
bool DoublyLinkedList<T>::isEmpty(){
    return numberOfNodes == 0;
}

//Returns a true/false value indicating if an element is present in the list
template < class T >
bool DoublyLinkedList<T>::find(const T& elem){
    bool retval = false;
    p_current = p_head;
    for(int i = 0; i < numberOfNodes; i++){
        if(p_current->data == elem){
            retval = true;
            break;
        }
        p_current = p_current->p_next;
    }
    return retval;
}

//Iterates from the head to the desired position
template < class T >
T& DoublyLinkedList<T>::at(int pos){
    if(pos < numberOfNodes){
        p_current = p_head;
        for(int i = 0; i < pos; i++){
            p_current = p_current->p_next;
        }
    }
    else{
        DoublyLinkedListException ex;
        throw ex;
    }
    return p_current->data;
}

//Returns the result of the at function
template < class T >
T& DoublyLinkedList<T>::operator[](int pos){
    return at(pos);
}
