//
// Created by 徐宇帆 on 18/2/24.
//

#ifndef PROJECT4_MYQUEUE_H
#define PROJECT4_MYQUEUE_H

/*
* Author:                 Yufan_Xu
* Assignment Title:       CSI 3334 - Project 4
* Assignment Description: This program is an implementation of a
*                         queue, which is a container for a
*                         doubly linked list
* Due Date:               02/27/2018
* Date Created:           02/24/2018
* Date Last Modified:     02/27/2018
*/

/*
 * Data Abstraction:
 *        This program contains a type C container, and the member
 *        functions for class myQueue
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

#include "myList.h"

template<class T, class C = myList<T> >
class myQueue {
public:
    /*
    * description: constructor
    * return: none
    * precondition: none
    * postcondition: none
    */
    myQueue();

    /*
    * description: destructor
    * return: none
    * precondition: none
    * postcondition: none
    */
    ~myQueue();

    /*
    * description: copy constructor
    * return: a copy of that
    * precondition: an object exists
    * postcondition: returns a copy of that value
    */
    myQueue(const myQueue&);

    /*
    * description:move copy constructor
    * return: copy that to this
    * precondition: an object exists
    * postcondition: returns a copy of that to this
    */
    myQueue(myQueue&&);

    /*
    * description: overloaded assignment operator
    * return: a copy of the rhs
    * precondition: an object exists
    * postcondition: returns a copy of the rhs
    */
    myQueue<T,C>& operator=(const myQueue&);

    /*
    * description: move assignment operator
    * return: a copy of the rhs to lhs
    * precondition: an object exists
    * postcondition: returns a copy of the rhs to lhs
    */
    myQueue<T,C>& operator=(myQueue&&);

    /*
    * description: true if queus is empty false othewise
    * return: true or false
    * precondition: an object exists
    * postcondition: returns true or false
    */
    bool IsEmpty();

    /*
    * description: return the first element
    * return: a copy of the first element
    * precondition: an object exists
    * postcondition: returns a copy of the first element
    */
    T First();

    /*
    * description: add a value at tail
    * return: *this
    * precondition: an object exists
    * postcondition: adds an element at tail
    */
    myQueue<T,C>& Enqueue(const T x);

    /*
    * description: remove a value at head
    * return: *this
    * precondition: an object exists
    * postcondition: removes an element at head
    */
    myQueue<T,C>& Dequeue();
private:
    C container;
};

template <class T, class C>
myQueue<T,C>::myQueue() {}

template <class T, class C>
myQueue<T,C>::~myQueue() {}

template <class T, class C>
myQueue<T,C>::myQueue(const myQueue &that) {
    this->container = (that.container);
}

template <class T, class C>
myQueue<T,C>::myQueue(myQueue &&that) {
    this->container = move(that.container);
}

template <class T, class C>
myQueue<T,C>& myQueue<T,C>::operator=(const myQueue &that) {
    if(this != &that) {
        this->container = that.container;
    }
    return *this;
}

template <class T, class C>
myQueue<T,C>& myQueue<T,C>::operator=(myQueue &&that) {
    if(this != &that) {
        this->container = move(that.container);
    }
    return *this;
}

template <class T, class C>
myQueue<T,C>& myQueue<T,C>::Dequeue() {
    this->container.popFront();
    return *this;
}

template <class T, class C>
myQueue<T,C>& myQueue<T,C>::Enqueue(const T x) {
    this->container.pushBack(x);
    return *this;
}

template <class T, class C>
T myQueue<T,C>::First() {
    return this->container.front();
}

template <class T, class C>
bool myQueue<T,C>::IsEmpty() {
    if (this->container.empty()) {
        return true;
    }
    return false;
}

#endif //PROJECT4_MYQUEUE_H
