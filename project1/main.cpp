/*
* Author:                 Yufan_Xu
* Assignment Title:       CSI 3334 - Project 2
* Assignment Description: This program tests the trace validation of
*                         the myStack container that we did for the
*                         previous project. If the trace was been
*                         detected as invalid, the program will print
*                         out where the error occurs and the
*                         error message, if all the traces are valid
*                         the program will print out the depth of the
*                         trace and the message to screen
* Due Date:               02/1/2018
* Date Created:           01/28/2018
* Date Last Modified:     02/1/2018
*/

/*
 * Data Abstraction:
 *        There are multiple variables with different types including
 *            string, myStack, int, bool, size_t, stringstream
 *        They are: callStack,
 *            lineNumber, maximumDepth, line, operation, function,
 *            top, top2, flag1, flag2, flag3, stackTop, temp1, temp2
 *            tempStack, currentT, str1 and so on
 * Input:
 *        The program prompts the input from the user, the program
 *            also prompts input file for only testing purpose, the
 *            user can use command line in order to achieve the best
 *            testing behavior
 * Process:
 *        The program will prompt input from the user and then analyze
 *            whether the trace of functions are valid, also there
 *            are four different input files that can be tested as
 *            will, but it is only for testing purposes, then the
 *            program will print the related information on screen
 * Output:
 *        The program will print different error messages if invalid
 *            trace has been found,
 * Assumptions:
 *        Assuming the program creater only wants the correct result
 */

#include <iostream>
#include <string>
#include "myStack.h"
#include <cassert>
#include <sstream>

using namespace std;

/* main
 *  parameters:
 *      argc -- the number of arguments from the command line
 *      argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 *  PUT YOUR COMMENTS FOR THIS FUNCTION HERE
 */
// QUESTION: WHAT ARE ARGC AND ARGV? GO LOOK THEM UP!
int main(int argc, char **argv) {
    string line;

    // the callStack is used for storing the names of
    // functions that have been
    // called and not yet returned
    myStack<string> callStack;

    // Each time we go through this while loop, we read a line of input.
    // The function getline() returns a reference to cin, which is
    // checked by
    // the while condition.  If cin has reached the end of the file,
    // it will
    // return false and the loop will exit.  Otherwise, it will return
    // true and
    // the loop will continue.

    // QUESTION: WHAT'S A SIZE_T TYPE? GO LOOK IT UP!
    size_t lineNumber = 0;
    size_t maximumDepth = 0;
    string operation, function;
    int top = 0;
    int top2 = 0;
    bool flag1;
    bool valid = true;
    bool flag2 = false;
    bool flag3 = false;
    string stackTop;
    string temp1;
    string temp2;
    myStack<string> tempStack;
    string currentT;
    stringstream str1;
    // QUESTION: WHAT DOES GETLINE() RETURN?
   while (getline(cin, line) && valid) {

        lineNumber++;

        str1 << line;
        str1 >> operation;
        str1 >> function;
        if (operation == "call") {
            callStack.push(function);
            top++;
        }
        else if (operation == "return") {
            currentT = function;
            if (!callStack.empty()) {
                if (currentT == callStack.top()) {
                    callStack.pop();
                    top--;
                }
                else if (currentT != callStack.top()) {
                    flag2 = true;
                    valid = false;

                    stackTop = callStack.top();

                    for (int i = 0; i < top; i++) {

                        if (currentT == callStack.top()) {
                            flag1 = true;
                            valid = false;


                            for (int i = 0; i < top2; i ++) {
                                temp1 = callStack.top();
                                callStack.push(temp2);
                                callStack.pop();
                            }
                        }
                        else if (currentT != callStack.top()){
                            flag1 = false;
                            valid = true;

                            temp2 = callStack.top();
                            tempStack.push(temp2);
                            callStack.pop();

                            top2++;
                        }
                    }

                    for (int i = 0; i < top2; i++) {
                        temp1 = tempStack.top();

                        callStack.push(temp1);

                        tempStack.pop();


                    }

                }
            }
            else if (callStack.empty())
            {
                flag3 = true;
                valid = false;

            }
        }
        if (maximumDepth <= top) {
                maximumDepth = top;
        }
    }


    if (flag1 == true) {


        cout << "Invalid trace at line "
             << lineNumber << endl;
        cout << "Returning from " << currentT
             << " instead of "
             << stackTop << endl;
        cout << "Stack Trace: " << endl;
        for (int i = 0;i < top; i ++) {
            cout << callStack.top() << endl;
            callStack.pop();
        }
    }
    else if (flag2 == true || flag3 == true) {
        cout << "Invalid trace at line " << lineNumber
             << endl;
        cout << "Returning from " << currentT
             << " which was not called" << endl;
        cout << "Stack Trace: " << endl;
        for (int i = 0;i < top; i ++) {
            cout << callStack.top() << endl;
            callStack.pop();
        }
    }
    else if (!callStack.empty() || lineNumber % 2 != 0) {
        if (flag3 == false) {
            cout << "Invalid trace at line " << lineNumber << endl;
            cout << "Not all fucntions returned" << endl;
            cout << "Stack trace: " << endl;

            for (int i = 0; i < top; i++) {
                cout << callStack.top() << endl;
                callStack.pop();
            }
        }
    }
    else {
        if (valid == true) {
            cout << "Valid trace" << endl;
            cout << "Maximum call depth was " << maximumDepth << endl;
        }
    }
    return 0;
}