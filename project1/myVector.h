#ifndef PROJECT1_MYVECTOR_H
#define PROJECT1_MYVECTOR_H

/*
* Author:                 Yufan_Xu
* Assignment Title:       CSI 3334 - Project 0
* Assignment Description: This program contains a self-written 'myVector' class
*                         inherent from 'ContainerInterface' class, the
*                         'myVector' class contains many of the self-written
*                         functions frombthe 'vector' class in the Standard
*                         Template Library.Further more, the whole program also
*                         contains a driver that was written by myself in order
*                         to test all thebvmember functions in the 'myVector'
*                         class
* Due Date:               01/18/2018
* Date Created:           01/13/2018
* Date Last Modified:     01/17/2018
*/

/*
 * Data Abstraction:
 *        There are 3 private member variables:
 *            T *data, int size, int capacity; 3 private member functions:
 *            grow(), shiftRight(), shiftLeft().
 *
 *        Constructor:
 *            myVector().
 *
 *        Big 5: ~myVector(), myVector(myVector<T>&), myVector<T>&
 *            operator=(myVector<T>&), myVector<T>& operator=(myVector<T>&&).
 *
 *        Other public members:
 *            containerInterface <T>&  pushFront(T), containerInterface <T>&
 *            pushBack(T), containerInterface <T>&  popFront( )
 *            containerInterface <T>&  popBack( )  throw (BADINDEX),
 *            int  getSize() const, bool full() const, bool empty() const,
 *            T    front() const throw (BADINDEX),
 *            T    back()  const throw (BADINDEX),
 *            T&   operator [](int) throw (BADINDEX), void erase().
 * Input:
 *        The program does not contain any input from the user, but the
 *            'TestDriver'assigns values to variables created by using the
 *            'myVector' class.
 * Process:
 *        The 'TestDriver' will first assign values to variable type 'myVector'
 *           'vec1', the n it will test all the member functions in the myVector
 *           class and print necessary information on screen.
 * Output:
 *        The 'TestDriver' will print appropriate output on screen after testing
 *            each member functions from the 'myVector' class
 * Assumptions:
 *        Assuming the TestDriver will test each function and print the correct
 *            output;
 *        Assuming the program writer only want the true result for each
 *            function.
 */

#include <iostream>             //for 'cout', '>>', etc
#include "containerInterface.h" //for the inheritance

using namespace std;

//using template in order to assign different variable type
template <typename T>

//myVector class inherited from containerInterface class
class myVector: public containerInterface<T>{

//public class members
public:

    /*
    * description: constructor of myVector class
    * return: no return type
    * precondition: no precondition
    * postcondition: set size to 0, capacity to 10, create a new data pointer
    *                with capacity of 10, type T
    *
    */
    myVector();

    /*
    * description: destructor of myVector class
    * return: no return type
    * precondition: there is at least one object of 'data' exist
    * postcondition: delete all memory that has been allocated
    *
    */
    ~myVector();

    /*
    * description: copy constructor of myVector class
    * return: no return type
    * precondition: there is at least one object of 'data' exist
    * postcondition: a copy of the class object 'that' is made
    *
    */
    myVector(myVector<T>&that);

    /*
    * description: move constructor of myVector class
    * return: no return type
    * precondition: there is at least one object of 'data' exist
    * postcondition: a copy of the class object 'that' is made
    *
    */
    myVector(myVector<T>&&that);

    /*
    * description: overloaded assignment operator of myVector class
    * return: *this
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object 'that' is unchanged and '*this' is an exact
    *                copy of 'that'
    *
    */
    myVector<T>& operator=(myVector<T>&that);

    /*
    * description: overloaded move assignment operator of myVector class
    * return: *this
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object 'that' is unchanged and '*this' moves to 'that'
    *
    */
    myVector<T>& operator=(myVector<T>&&that);

    /*
    * description: add data element 'e' to the front of the vector
    * return: a reference to self
    * precondition: there is at least one object of 'data' exist
    * postcondition: if size == capacity is true, call shiftRight()
    *
    */
    containerInterface <T>&  pushFront(T e);

    /*
    * description: add data element 'e' to the back of the vector
    * return: a reference to self
    * precondition: there is at least one object of 'data' exist
    * postcondition:  if size == capacity, increment size
    *
    */
    containerInterface <T>&  pushBack(T);

    /*
    * description: removes a data element from the front of the array
    * return: a reference to self
    * precondition: there is at least one object of 'data' exist
    * postcondition: the first element has been removed  from the front of the
    * myVector, decrement size, throw BADINDEX() if the array is empty
    *
    */
    containerInterface <T>&  popFront( ) throw (BADINDEX);

    /*
    * description: removes a data element from the end of the array
    * return: a reference to self
    * precondition: there is at least one object of 'data' exist
    * postcondition: the last element has been removed  from the front of the
    * myVector, decrement size, throw BADINDEX() if the array is empty
    */
    containerInterface <T>&  popBack( )  throw (BADINDEX);

    /*
    * description: returns the number of elements in the 'data' array
    * return: int
    * precondition: there is at least one object of 'data' exist
    * postcondition: the 'data' elements are unchanged
    *
    */
    int  getSize() const;

    /*
    * description: returns state information about the list
    * return: true if the 'myVector' cannot grow false otherwise
    * precondition: there is at least one object of 'data' exist
    * postcondition: object is unchanged
    *
    */
    bool full() const;

    /*
    * description: returns state information about the list
    * return: true if the 'myVector' is empty false otherwise
    * precondition: there is at least one object of 'data' exist
    * postcondition: the 'myVector' is unchanged
    *
    */
    bool empty() const;

    /*
    * description: returns a copy of the first data item in 'myVector'
    * return: type T
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object is unchanged, if empty throw BADINDEX()
    *
    */
    T    front() const throw (BADINDEX);

    /*
    * description: returns a copy of the last data item in 'myVector'
    * return: type T
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object is unchanged, if empty throw BADINDEX()
    *
    */
    T    back()  const throw (BADINDEX);

    /*
    * description: returns a reference to data element n in 'myVector'
    * return: type T
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object is unchanged, if empty throw BADINDEX()
    *
    */
    T&   operator [](int n) throw (BADINDEX);

    /*
    * description: removes all elements from the 'data' array
    * return: void
    * precondition: there is at least one object of 'data' exist
    * postcondition: the object size is set to zero
    *
    */
    void erase();

//private class members
private:
    T    *data;    //pointer 'data' with variable type T
    int  size;     //the size of pointer 'data'
    int  capacity; //the capacity of pointer 'data'

    /*
    * description: doubles the capacity of the vector
    * return: void
    * precondition: there is at least one object of 'data' exist
    * postcondition: capacity is doubled, new memory is allocated and the
    *                information stored in data is copied in the new
    *                memory.Old memory is deallocated, data points to the
    *                new memory.
    */
    void grow();

    /*
    * description: shift all the information stored in data one position to
    * the right. Increments size, and grows the vector if size > capacity.
    * return: void
    * precondition: there is at least one object of 'data' exist
    * postcondition: if size > 0 this function shifts all the information
    * stored in data one position to the right, and increments size.
    *
    */
    void shiftRight();

    /*
    * description: shift all the information stored in data one position
    *              to the left, decrements size
    * return: void
    * precondition: there is at least one object of 'data' exist
    * postcondition: if size > 0 this function shifts all the information
    *                stored in data one position to the left, and decrements
    *                size.
    *
    */
    void shiftLeft();
};

template <typename T>
myVector<T>::myVector() {
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

template <typename T>
myVector<T>::~myVector() {
    delete [] this->data;
    this->data = NULL;
}

template <typename T>
myVector<T>::myVector(myVector<T> &that) {
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new T[this->capacity];

    for (int i = 0; i < this->size; i ++) {
        this->data[i] = that.data[i];
    }
}

template <typename T>
myVector<T>::myVector(myVector<T> &&that): size{that.size},
                                           capacity{that.capacity}{
    swap(this->data, that.data);
    that.data = nullptr;
}

template <typename T>
myVector<T>& myVector<T>::operator=(myVector<T> &that) {
    if (this != &that) {
        delete [] this->data;
        this->data = NULL;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new T[this->capacity];

        for (int i = 0; i < this->size; i ++) {
            this->data[i] = that.data[i];
        }
    }

    return *this;
}

template <typename T>
myVector<T>& myVector<T>::operator=(myVector<T> &&that) {
    if (this != &that) {
        this->size = that.size;
        this->capacity = that.capacity;
        swap(this->data, that.data);
    }

    return *this;
}

template <typename T>
T myVector<T>::front() const throw (BADINDEX){
    if (empty()) {
        throw BADINDEX();
    }

    return this->data[0];

}

template <typename T>
T myVector<T>::back() const throw (BADINDEX){
    if (empty()) {
        throw BADINDEX();
    }

    return this->data[this->size - 1];
}

template <typename T>
containerInterface <T>& myVector<T>::pushFront(T e) {
    grow();
    shiftRight();
    this->data[0] = e;

    return *this;
}

template <typename T>
containerInterface <T>& myVector<T>::pushBack(T e) {
    grow();
    this->data[this->size] = e;
    this->size ++;

    return *this;
}

template <typename T>
containerInterface <T>& myVector<T>::popFront() throw (BADINDEX){
    if (empty()) {
        throw BADINDEX();
    }

    this->shiftLeft();
    return *this;
}

template <typename T>
containerInterface <T>& myVector<T>::popBack() throw (BADINDEX){
    if (empty()) {
        throw BADINDEX();
    }

    this->size --;
    return *this;
}

template <typename T>
int myVector<T>::getSize() const {
    return this->size;
}

template <typename T>
bool myVector<T>::full() const {
    if (this->size == this->capacity) {
        return true;
    }

    return false;
}

template <typename T>
bool myVector<T>::empty() const {
    if (this->size == 0) {
        return true;
    }

    return false;
}

template <typename T>
T & myVector<T>::operator[](int n) throw (BADINDEX){
    if (n >= this->capacity || n < 0) {
        throw BADINDEX();
    }

    return this->data[n];
}

template <typename T>
void myVector<T>::erase() {
    if (!empty()) {
        this->size = 0;
    }
}

template <typename T>
void myVector<T>::grow() {
    if (full()) {
        T *old = this->data;
        this->capacity *= 2;
        this->data = new T[this->capacity];

        for (int i = 0; i < this->size; i ++) {
            this->data[i] = old[i];
        }
        delete [] old;
        old = NULL;
    }
}

template <typename T>
void myVector<T>::shiftLeft() {
    for (int i = 0; i < this->size; i ++) {
        this->data[i] = this->data[i + 1];
    }

    this->size --;
}

template <typename T>
void myVector<T>::shiftRight() {
    if (full()) {
        grow();
    }

    for (int i = this->size; i > 0; i --) {
        this->data[i] = this->data[i - 1];
    }

    this->size ++;
}

#endif //PROJECT1_MYVECTOR_H
