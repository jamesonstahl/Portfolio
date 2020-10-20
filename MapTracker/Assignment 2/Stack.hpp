#pragma once

#include <iostream>
#include "DoublyLinkedList.h"
#include "StackUnderFlow.h"

using namespace std;

template < class T >
class Stack{
public:
    Stack();
    ~Stack();
    void push(const T& elem);
    T pop();
    T top();
    int size();
    bool isEmpty();
private:
    DoublyLinkedList <T> list;
};

template < class T>
Stack<T>::Stack(){
    
}
 
template < class T >
Stack<T>::~Stack(){
    
}

//Inserts passed in element to the top of the stack
template < class T >
void Stack<T>::push(const T& elem){
    list.insertAtFront(elem);
}

//While the stack is not empty, removes the object at the top of the stack
template < class T >
T Stack<T>::pop(){
    T data;
    if(!list.isEmpty()){
        list.removeFromFront(data);
    }
    else{
        StackUnderFlow ex;
        throw ex;
    }
    return data;
}

//Returns the top of the stack
template < class T >
T Stack<T>::top(){
    if(list.isEmpty()){
        StackUnderFlow ex;
        throw ex;
    }
    else{
        return list[0];
    }
}

//Returns the size of the stack
template < class T >
int Stack<T>::size(){
    return list.size();
}

//Returns the logical value if the number of nodes being used is 0 or not
template < class T >
bool Stack<T>::isEmpty(){
    return list.isEmpty();
}
