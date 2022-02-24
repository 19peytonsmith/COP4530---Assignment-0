#ifndef STACK_H
#define STACK_H
// Created by David A Gaitros on 10/15/19.
// ********************************************************************
// * Name: Stack Class                                                *
// * Description: A template Stack class designed to be used with     *
// * any simple C++ type to include floating point, double            *
// * floating point, character, and Boolean.                          *
// * The stack pointer, as is the convention, points to the last      *
// * or highest element in the array. So if you allocate 100          *
// * elements of type "T" then the first empty element will be 99.    *
// * Author: Dr. David A. Gaitros                                     *
// * Date: January 19, 2019                                           *
// ********************************************************************
#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <typename T> class Stack;
template <typename T> ostream & operator <<(ostream & os,  Stack<T> &obj);
template <typename T>
class Stack {
public:
    Stack();                    // Default Constructor, stack is size 100.
    Stack(const int size);      // Constructor, creates stack of size "size"
    Stack(const Stack & Obj);   // Copy constructor
    ~Stack();                   // Destructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    int Number();               // Return the number of elements stored
    T Top();                    // Returns the top element, does not pop it
    bool Push (const T item);   // Put an item on the stack
    bool Pop();                 // Pop an item off and display to std out
    Stack<T> &operator = (Stack<T> & s); // = operator overload.
    friend ostream &operator << <T>(ostream & os, Stack<T> &s)
    {
        if(s.Empty()){
            os << "Error: Empty Stack" << endl;
        }
        else{
            os << s.Top() << endl;
            s._top--;
        }
        return os;
    }

protected:
    T * _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
    int _number;                // The number of elements in the stack.
};

// Default Constructor with no parameters that
// sets _size to the DEFAULTSIZE constant (100)
// allocates the memory for _stack, initializes
// member variables, then sets the values of _stack to zeros.
template<class T>
Stack<T>::Stack() {
    // Define/initialize member variables
    // and allocate memory for _stack.
    _size = DEFAULTSIZE;
    _stack = new T [_size];
    _number = DEFAULTSIZE;
    _top = -1;
    for(int index = 0; index<_size; index++){
        _stack[index] = 0;
    }
}
// Parametrized Constructor with one parameter, size, that
// checks to see if size is valid, and sets _size to size,
// allocates the memory for _stack, initializes member variables,
// then initializes the values of _stack to zeros.
template<class T>
Stack<T>::Stack(const int size) {
    // If size is less than 1, default _size to 1
    // else, set _size to size.
    if(size<1) _size = 1;
    else _size = size;
    _stack = new T [_size];
    _number = size;
    _top = -1;
    for(int index = 0; index<_size; index++){
        _stack[index] = 0;
    }
}
// Copy Constructor with one object parameter, item, that copies
// the _size, allocates memory for _stack, initializes member
// variables, then copies all of _stack's elements over.
template<class T>
Stack<T>::Stack(const Stack<T> &item) {
    // Copy over member variables and
    // allocate memory for _stack.
    _size = item._size;
    _stack = new T [_size];
    _number = _size;
    _top = -1;
    for(size_t i = 0; i < _size; ++i){
        _stack[i] = item._stack[i];
    }
}
// Destructor that destroys and
// deallocates the memory for _stack.
template<class T>
Stack<T>::~Stack() {
    delete [] _stack;
}
// *****************************************************************
// * Function Name:  Full()                                        *
// * Description:  Will return the truth value on whether          *
// * or not the stack is full.                                     *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
bool Stack<T>::Full() {
    // If _top == _number-1, then the stack is full.
    return _top == _number-1;
}
// *****************************************************************
// * Function Name:  Empty()                                       *
// * Description:  Will return the truth value on whether          *
// * or not the stack is empty.                                    *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
bool Stack<T>::Empty() {
    // If _top == -1, then the stack is empty.
    return _top == -1;
}
// *****************************************************************
// * Function Name:  Size()                                        *
// * Description:  Will return the allocated size of the stack.    *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
int Stack<T>::Size() {
    // Returns the allocated size of stack
    return _size;
}
// *****************************************************************
// * Function Name:  Number()                                       *
// * Description:  Will return the number of stored elements.      *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
int Stack<T>::Number() {
    // Returns the allocated size of stack
    return _number;
}
// *****************************************************************
// * Function Name:  Top()                                         *
// * Description:  Will return the top element of the stack.       *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
T Stack<T>::Top() {
    // Returns the top element of the stack
    return _stack[_top];
}
// *****************************************************************
// * Function Name:  Push()                                        *
// * Description:  Will add the parameter element to the           *
// * top of the stack if possible.                                 *
// * Parameter Description: One const T parameter, item, that      *
// * will be added to the stack if possible.                       *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
bool Stack<T>::Push(const T item) {
    // If the stack is full, output an error and
    // return false, else increment top and add it
    // to the stack and return true.
    if(Full()){
        cout << "Error: Full Stack" << endl;
        return false;
    }
    else{
        ++_top;
        _stack[_top] = item;
        return true;
    }
}
// *****************************************************************
// * Function Name:  Pop()                                         *
// * Description:  Will remove (pop) the top element from          *
// * the stack.                                                    *
// * Parameter Description:   No parameters                        *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<class T>
bool Stack<T>::Pop() {
    // If the stack is empty, output an error and
    // return false, else decrement top and return true.
    if(Empty()){
        cout << "Error: Empty Stack" << endl;
        return false;
    }
    else{
        cout << Top() << endl;
        _top--;
        return true;
    }
}
// *****************************************************************
// * Function Name:  operator =()                                  *
// * Description:  Assignment operator overload function that      *
// * will copy the contents of one stack object to another.        *
// * Parameter Description:  One const Stack object parameter, s,  *
// * that will copy this object to another object.                 *
// * Date:  06/09/2021                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  No References                                    *
// *****************************************************************
template<class T>
Stack<T> & Stack<T>::operator=(Stack<T> s) {
    // Copy over the size/stack elements.
    _size = s._size;
    for(size_t i = 0; i < _size; ++i){
        _stack[i] = s._stack[i];
    }
}
#endif