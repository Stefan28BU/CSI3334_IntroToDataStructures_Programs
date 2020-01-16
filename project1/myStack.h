/*
* Author:                 Yufan_Xu
* Assignment Title:       CSI 3334 - Project 1
* Assignment Description: This program contains a self-written class
*                         called myStack, it is used as a container of
*                         myVector class from the previous project
                          'myVector' class
* Due Date:               01/28/2018
* Date Created:           01/20/2018
* Date Last Modified:     01/27/2018
*/

/*
 * Data Abstraction:
 *        There are 1 private member variables:
 *            C *container
 *
 *        Constructor:
 *            myStack().
 *
 *        Big 5: ~myStack(), myStack(myStack<T>&), myStack<T>&
 *            operator=(myStack<T>&), myStack<T>& operator=(myStack<T>&&)
 *
 *        Other public members:
 *            empty(), push(x), pop(), top()
 * Input:
 *        The program does not contain any input from the user
 * Process:
 *        The program upload site will test the myStack container
 * Output:
 *        The output will be printed on the program upoad site
 * Assumptions:
 *        Assuming the program creater only wants the correct result
 */

#ifndef PROJECT1_MYSTACK_H
#define PROJECT1_MYSTACK_H

#include "myVector.h"

using namespace std;

template<class T, class C = myVector<T> >
class myStack {
public:
    /*
    * description: constructor of the myStack container
    * return: nothing
    * precondition: nothing
    * postcondition: nothing
    */
    myStack();

    /*
    * description: copy constructor of the myStack container
    * return: nothing
    * precondition: an object exists
    * postcondition: a copy of myStack container is made
    */
    myStack(const myStack<T, C>&);

    /*
    * description: move constructor of the myStack container
    * return: nothing
    * precondition: an object exists
    * postcondition: 'that' is unchanged and '*this' move to the
    *                 exact copy of 'that'
    */
    myStack(myStack<T, C>&&);

    /*
    * description: operator = of the myStack container
    * return: *this
    * precondition: an object exists
    * postcondition: 'that' is unchanged and '*this' is the
    *                 exact copy of 'that'
    */
    myStack<T, C>& operator= (myStack<T, C>&);

    /*
    * description: move operator = of the myStack container
    * return: *this
    * precondition: an object exists
    * postcondition: 'that' is unchanged and '*this' moves to the
    *                 exact copy of 'that'
    */
    myStack<T, C>& operator= (myStack<T, C>&&);

    /*
    * description: destructor of the myStack container
    * return: nothing
    * precondition: nothing
    * postcondition: nothing
    */
    ~myStack();

    /*
    * description: returns true if container is empty false
    *              otherwise
    * return: true or false
    * precondition: an object exists
    * postcondition: returns true or false
    */
    bool empty();

    /*
    * description: returns the top element of container
    * return: T
    * precondition: an object exists
    * postcondition: returns a copy of the top element of
    *                myStack container
    */
    T top();

    /*
    * description: pushes an element into the container
    * return: *this
    * precondition: an object exists
    * postcondition: pushes an element to the back
    */
    myStack<T, C>& push( T x);


    /*
    * description: removes an element into the container
    * return: *this
    * precondition: an object exists
    * postcondition: removes an element from the back
    */
    myStack<T, C>& pop();

private:
    C container;
};

template <class T, class C>
myStack<T, C>::myStack() {}

template <class T, class C>
myStack<T, C>::~myStack() {}

template <class T, class C>
myStack<T, C>& myStack<T,C>::operator=(myStack<T, C> &that) {
    if(this != &that) {
        this->container = that.container;
    }

    return *this;
}

template <class T, class C>
myStack<T, C>::myStack(const myStack<T, C> &that) {
    this->container = (that.container);
}

template <class T, class C>
myStack<T, C>& myStack<T,C>::operator=(myStack<T, C> &&that) {
    if(this != &that) {
        this->container = move(that.container);
    }
    return *this;
}

template <class T, class C>
myStack<T, C>::myStack(myStack<T, C> &&that) {
    this->container = move(that.container);
}

template <class T, class C>
bool myStack<T, C>::empty() {
    if (this->container.empty()) {
        return true;
    }
    return false;
}

template <class T, class C>
myStack<T, C>& myStack<T, C>::push(T x) {
    this->container.pushBack(x);

    return *this;
}

template <class T, class C>
myStack<T, C>& myStack<T, C>::pop() {
    this->container.popBack();

    return *this;
}

template <class T, class C>
T myStack<T, C>::top() {
    return this->container.back();
}





#endif //PROJECT1_MYSTACK_H
