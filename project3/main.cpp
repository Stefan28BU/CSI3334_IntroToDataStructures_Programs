

#include <iostream>
#include "myList.h"

using namespace std;

int main() {

    myList<int> list1;

    for (int i = 0; i < 10; i ++) {
        list1.pushFront(i);
    }

    for (int i = 0; i < list1.getSize(); i ++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    cout << list1.getSize()<< endl;

    for (int i = 0; i < 10; i ++) {
        list1.pushBack(i);
    }

    for (int i = 0; i < list1.getSize(); i ++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    list1.popFront();
    list1.pushFront(99);
    list1.pushBack(199);

    for (int i = 0; i < list1.getSize(); i ++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    cout << list1.front() << endl;
    cout << list1.back() << endl;

    list1.popBack();
    list1.pushBack(200);




    cout << list1.getSize() << endl;

    for (int i = 0; i < list1.getSize(); i ++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    cout << list1.empty() << endl;

    myList<int> list2;

    list2 = list1;

    for (int i = 0; i < list2.getSize(); i ++) {
        cout << list2[i] << " ";
    }
    cout << endl;

    list2.pushBack(200);

    cout << list2[19] << endl;

    cout << list2.getSize() << endl;


/*
    myList<int> list2;
    list2 = list1;
    list2.pushFront(99);
    list2.pushBack(100);
    list2.pushFront(66);

    for (int i = 0; i < list2.getSize(); i ++) {
        cout << list2[i] << " ";
    }
    cout << endl;


    cout << list2.front() << endl;
    cout << list2.back() << endl;

    myList<string> list3;

    list3.pushBack("hello");
    list3.pushBack("world");

    for (int i = 0; i < list3.getSize(); i ++) {
        cout << list3[i] << " ";
    }
    cout << endl;

    list3.popFront();

    for (int i = 0; i < list3.getSize(); i ++) {
        cout << list3[i] << " ";
    }
    cout << endl;

    list3.popBack();
    list3.pushBack("hi");
    cout <<list3[0] << endl;
    list3.popFront();

    myList<int> list4;

    list4 = list2;

    for (int i = 0; i < list4.getSize(); i ++) {
        cout << list4[i] << " ";
    }
    cout << endl;
    */


    myList<int> list3;



    return 0;
}