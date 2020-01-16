




//
// Created by 徐宇帆 on 18/2/10.
//

#ifndef PROJECT3_MYLIST_H
#define PROJECT3_MYLIST_H

/*
* Author:                 Yufan_Xu
* Assignment Title:       CSI 3334 - Project 3
* Assignment Description: This program is an implementation of a
*                         dequeue, which is a doubly linked list that
*                         contains a head and a tail. This is much
*                         more efficient than a singly linked list
*                         because the insert and pop only takes
*                         constant time instead of linear time
* Due Date:               02/15/2018
* Date Created:           02/01/2018
* Date Last Modified:     02/15/2018
*/

/*
 * Data Abstraction:
 *        This program contains a struct called node and a class
 *            called myList, myList is implemented from an abstract
 *            class that containerInterface, the node struct
 *            contains multiple variables and a constructor, the
 *            myList class contains a head and a tail, and big-5
 *            with other operations
 * Input:
 *        This program does not contain any user input, it will be
 *            uploaded on the upload site and tested by the driver
 *            on the website
 * Process:
 *        The program itself does not contain any input from the user
 *            which means the program itself would not compile
 * Output:
 *        There is not output on the screen
 * Assumptions:
 *        Assuming the program creater only wants the correct result
 */

#include <memory>
#include <iostream>
#include "containerInterface.h"

using namespace std;

//node structure
template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *back;

    /*
     * description: calculate total price of item with tax
     * return: double
     * precondition: price and tax are valid
     * postcondition: returns sum of price and tax
     *
     */
    node(T e){
        data = e;
        next = nullptr;
        back = nullptr;
    }
};

template <class T>
class myList:public containerInterface<T>
{
public:
    /*
     * description: constructor
     * return: none
     * precondition: none
     * postcondition:  tail and head points to NULL
     *
     */
    myList();

    /*
     * description: destructor
     * return: none
     * precondition: an object exists
     * postcondition: delete all allocated memory
     *
     */
    ~myList();

    /*
     * description: copy constructor
     * return: none
     * precondition: an object exists
     * postcondition: a copy of the object is made
     *
     */
    myList(const myList<T>&);

    /*
     * description: move copy constructor
     * return: none
     * precondition: an object exists
     * postcondition: a copy of the object is moved to left
     *
     */
    myList(myList<T>&&);

    /*
     * description: insert nodes at head
     * return: *this
     * precondition: an object exists
     * postcondition: a new node is added to the front
     *
     */
    myList<T>& pushFront(T);

    /*
     * description: insert nodes at tail
     * return: *this
     * precondition: an object exists
     * postcondition: a new node is added to the back
     *
     */
    myList<T>& pushBack(T);

    /*
     * description: remove a node at head
     * return: *this
     * precondition: an object exists
     * postcondition: remove a node at front
     *
     */
    myList<T>& popFront( )	throw(BADINDEX);

    /*
     * description: remove a node at tail
     * return: *this
     * precondition: an object exists
     * postcondition: remove a node at back
     *
     */
    myList<T>& popBack( )	throw(BADINDEX);

    /*
     * description: get the size of the list
     * return: number of nodes in the list
     * precondition: an object exists
     * postcondition: return the number of nodes in the list
     *
     */
    int  getSize() const;

    /*
     * description: return true is cannot add new node
     *              false otherwise
     * return: true if cannot add new node false otherwise
     * precondition: an object exists
     * postcondition: returns true or false
     *
     */
    bool full() const;

    /*
     * description: return true is list is empty
     * return: true or false
     * precondition: an object exists
     * postcondition: returns true if list is empty false
     *                otherwise
     *
     */
    bool empty() const;

    /*
     * description: get the first element
     * return: T
     * precondition: an object exists
     * postcondition: returns a copy of the first element
     *                if list is empty throws BADINDEX
     *
     */
    T  front()	const		throw(BADINDEX);

    /*
     * description: get the last element
     * return: T
     * precondition: an object exists
     * postcondition: returns a copy of the first element
     *                if list is empty throws BADINDEX
     *
     */
    T  back()	const		throw(BADINDEX);

    /*
     * description: returns the data at index entered
     * return: T
     * precondition: an object exists
     * postcondition: returns the data at index entered,
     *                throws BADINDEX if n is less than 0,
     *                or n is greater than or equal to
     *                size, or the list is empty
     *
     */
    T& operator [](int)	throw(BADINDEX);

    /*
     * description: delete all nodes in the list
     * return: void
     * precondition: an object exists
     * postcondition: remove all the nodes in the list
     *
     */
    void erase();

    /*
     * description: overloaded assignment operator
     * return: *this
     * precondition: an object exists
     * postcondition: n is unchanged and lhs is the copy
     *                of n
     *
     */
    myList<T>& operator = (const myList<T>&);

    /*
     * description: move assignment operator
     * return: *this
     * precondition: an object exists
     * postcondition: n is unchanged and moves to lefe as
     *                an exact copy
     *
     */
    myList<T>& operator = (myList<T>&&);
private:
    node<T> *head;
    node<T> *tail;
};

template <class T>
myList<T>::myList() {
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
myList<T>::~myList() {
    this->erase();
}

template <class T>
myList<T>::myList(const myList<T> &n) {
    if (n.head != NULL) {
        this->head = NULL;
        this->tail = NULL;
        node<T> *temp = n.head;
        while (temp != NULL) {
            this->pushBack(temp->data);
            temp = temp->next;
        }
    }
    else if (n.head == NULL) {
        this->head = NULL;
        this->tail = NULL;
    }
}

template <class T>
myList<T>::myList(myList<T> &&n):head{n.head}, tail{n.tail}{
    n.head = NULL;
    n.tail = NULL;
}

template <class T>
myList<T>& myList<T>::pushFront(T n) {
    node<T> *temp = new node<T>(n);
    temp->next = this->head;

    if (this->head == NULL) {
        this->tail = temp;
    }
    else if (this->head != NULL){
        temp->next->back = temp;
    }
    this->head = temp;

    return *this;
}

template <class T>
myList<T>& myList<T>::pushBack(T n) {
    if (this->head == NULL) {
        this->head = new node<T>(n);
        this->tail = this->head;
    }
    else {
        node<T> *temp = new node<T>(n);
        this->tail->next = temp;
        temp->back = this->tail;
        this->tail = temp;
    }
    return *this;
}

template <class T>
myList<T>& myList<T>::popFront() throw(BADINDEX){
    if(this->empty()) {
        throw BADINDEX();
    }
    node<T> *temp = this->head;
    this->head = this->head->next;
    temp->next = NULL;

    delete temp;

    return *this;
}

template <class T>
myList<T>& myList<T>::popBack() throw(BADINDEX){
    if (this->empty()) {
        throw BADINDEX();
    }
    else if (this->head->next == NULL) {
        delete this->head;
        this->tail = NULL;
        this->head = NULL;
    }
    else if (this->head != NULL) {
        node<T>* temp = this->tail;
        this->tail = this->tail->back;
        delete temp;
        temp = NULL;
    }
    return *this;
}

template <class T>
int myList<T>::getSize() const {
    int size = 0;
    node<T> *temp = this->head;
    while (temp != NULL) {
        size ++;
        temp = temp->next;
    }
    return size;
}

template <class T>
bool myList<T>::full() const {
    return false;
}

template <class T>
bool myList<T>::empty() const {
    return this->head == NULL;
}

template <class T>
T myList<T>::front() const throw(BADINDEX){
    if(this->empty()) {
        throw BADINDEX();
    }
    return this->head->data;
}

template <class T>
T myList<T>::back() const throw(BADINDEX){
    if(this->empty()) {
        throw BADINDEX();
    }
    return this->tail->data;
}

template <class T>
T& myList<T>::operator[](int n) throw(BADINDEX){
    if(this->empty() || n < 0 || n >= getSize()) {
        throw BADINDEX();
    }
    node<T> *temp = this->head;

    int i = 0;

    while (i < n) {
        temp = temp->next;
        i ++;
    }
    return temp->data;
}

template <class T>
void myList<T>::erase() {
    node<T> *temp;

    while (this->head != NULL) {
        temp = this->head;
        this->head = this->head->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
    }
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
myList<T>& myList<T>::operator=(const myList<T> &n) {
    if (this != &n) {
        this->erase();

        if (n.head != NULL) {
            this->head = NULL;
            this->tail = NULL;
            node<T> *temp = n.head;
            while (temp != NULL) {
                this->pushBack(temp->data);
                temp = temp->next;
            }
        }
        else if (n.head == NULL) {
            this->head = NULL;
            this->tail = NULL;
        }
    }
    return *this;
}

template <class T>
myList<T>& myList<T>::operator=(myList<T> &&n) {
    if (this!= &n) {
        swap(this->head, n.head);
        swap(this->tail, n.tail);
    }
    return *this;
}


#endif //PROJECT3_MYLIST_H
