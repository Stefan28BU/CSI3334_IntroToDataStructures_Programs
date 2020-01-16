/*
 * Author:                 Yufan Xu
 * Assignment Title:       Sorting Visualization
 * Assignment Description: This program uses SDL_Plotter.h and generates
 *                         a window to show each visualization for each
 *                         of the different sorting algorithms.
 * Due Date:               03/25/2018
 * Date Created:           03/23/2018
 * Date Last Modified:     03/25/2018
 */

/*
 * Data Abstraction:
 * 		4 global variables, 8 functions and a main function. Types includes
 * 		    void, int, const int, bool, SDL_Plotter
 * Input:
 * 		The program reads inputs from the user and it will display
 * 		    the matching result for each of the key from the user input
 * Process:
 *      The program will first prompt the input from the users so it can
 *          read which sorting algorithm that the user whats to see, then
 *          the program will display the visualization that the user wants
 *          to see
 * Output:
 * 		The program generates a window to display multiple visualizations for
 * 		    each sorting algorithm
 * Assumptions:
 * 		Assuming the user only wants the correct results, assuming the user
 * 		    will eventually input the command that generates the results
 */

#include "SDL_Plotter.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

SDL_Plotter *g;
int *data;
const int SPEED = 3;
bool TRACE = false;

//************************************************************
// description: Sorts the data by recursively dividing the data in half
//              and recursively sorting the subsets
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void MergeSort(int *, int , int );

//************************************************************
// description: Merge data into temp array and merge together
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void Merge(int*, int*, int, int, int);

//************************************************************
// description: partition function of quicksort
// return: int
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
int partition(int, int);

//************************************************************
// description: Organizing data
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void plotData();

//************************************************************
// description: Generates random data
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void RandomizeData();

//************************************************************
// description: Sorts the data by swapping the data until all data is in the
//              correct location.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted
//
//************************************************************
void BubbleSort();

//************************************************************
// description: Sorts the data by searching the data for the next element
//              and sorting it.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void SelectionSort();

//************************************************************
// description: Sorts the data by inserting each element into the correct
//              sorted spot.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void InsertionSort();

//************************************************************
// description: Sorts the data by creating a heap and removing the top element
//              then reheaping with the remaining data and repeating
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void HeapSort();

//************************************************************
// description: Sorts the data by recursively dividing the data in half
//              and recursively sorting the subsets
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void QuickSort(int,int);

//************************************************************
// description: Sorts the data by recursively dividing the data in half and
//              sorting the subsets
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void MergeSort(int left, int right);

// Sorting Visualization Driver
int main(int argc, char **argv) {
    g = new SDL_Plotter(400,400);
    data = new int[g->getCol()];
    int x1, y1;

    for(int i =0; i < g->getCol(); i++){
        data[i] = rand()%g->getCol();
    }

    while(!g->getQuit()){

        if (g->getMouseClick(x1, y1)) {
            cout << "the mouse has been clicked: "
                 << x1 << " " << y1 << endl;
        }

        if(g->kbhit()){
            switch(g->getKey()){
                case 'B': BubbleSort();
                    break;
                case 'R': RandomizeData();
                    break;
                case 'S': SelectionSort();
                    break;
                case 'I': InsertionSort();;
                    break;
                case 'H': HeapSort();
                    break;
                case 'Q': QuickSort(0, g->getCol());
                    break;
                case 'M': MergeSort(0, g->getCol());
                    break;
                case 'T': TRACE = !TRACE;
                    break;
                case 'C': g->clear();
                    break;
                case 'X': g->setQuit(true);
                    break;
            }
        }

        plotData();
    }
}

// Bubble Sort
void BubbleSort(){
    for(int i = 0; i < g->getCol()-1; i++){
        for(int j = 0; j < g->getCol()-1-i; j++){
            if(data[j] > data[j+1]){
                swap(data[j], data[j+1]);
            }
        }
        //call plot data using SDL header file
        plotData();
    }
}

//Selection sort
void SelectionSort(){
    //initializing values
    int startScan, minIndex, minVal;
    for (startScan = 0; startScan < g->getCol()-1; startScan++) {
        minIndex = startScan;
        minVal = data[startScan];

        for (int i = startScan+1; i < g->getCol(); i ++) {
            if (data[i] < minVal) {
                minVal = data[i];
                minIndex = i;
            }
        }
        data[minIndex] = data[startScan];
        data[startScan] = minVal;
        plotData();
    }
}

//insertion sort algorithm
void InsertionSort(){
    //initializing variables
    int i, key, j;
    for (i = 1; i < g->getCol(); i++)
    {
        key = data[i];
        j = i-1;

        while (j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j = j-1;
        }
        data[j+1] = key;

        //call function for visualizing using the
        //SDL_plotter header file
        plotData();
    }
}


//heap sort algorithm using make_heap
//included in class <algorithm>
void HeapSort()
{
    for (int i = g->getCol(); i >1; i --) {
        make_heap(data,data+i);
        swap(data[0],data[i-1]);

        //call function for the visualization
        //using SDL header file
        plotData();
    }
}

//quicksort algorithm
void QuickSort(int left, int right)
{
    if (left < right) {
        int p = partition(left,right);
        QuickSort(left, p-1);
        QuickSort(p+1,right);
    }
    //call function for the visualization
    //using SDL header file
    plotData();
}

//partition is for the first part og the
//mergesort algorithm
//this function determines the key values
//read by the mergesory algorithm
int partition(int start, int end) {
    int piVal = data[start];
    int pivPos = start;

    for (int i = start+1; i <= end; i++) {
        if (data[i] < piVal) {
            swap(data[pivPos+1],data[i]);
            swap(data[pivPos],data[pivPos+1]);
            pivPos++;
        }
    }
    return pivPos;
}

void MergeSort(int left, int right)
{
    int temp[g->getCol()];
    MergeSort(temp, left, right);
}

void MergeSort(int *temp, int left, int right) {
    if (left < right) {
        int q = (left + right) / 2;
        MergeSort(temp,left, q);
        MergeSort(temp,q + 1, right);
        Merge(data, temp, left, q + 1, right);
    }
    plotData();
}

//merge sort algorithm
void Merge(int *data, int *temp, int left, int right, int rightend) {
    int leftEnd = right - 1;
    int tmPos = left;
    int numEle = rightend - left + 1;

    while (left <= leftEnd && right <= rightend) {
        if (data[left] <= data[right]) {
            temp[tmPos++] = move(data[left++]);
        }
        else {
            temp[tmPos++] = move(data[right++]);
        }
    }

    while (left <= leftEnd) {
        temp[tmPos++] = move(data[left++]);
    }

    while (right <= rightend) {
        temp[tmPos++] = move(data[right++]);
    }

    for (int i = 0; i < numEle; ++i, --rightend) {
        data[rightend] = move(temp[rightend]);
    }
}

// Select Random Data
void RandomizeData(){
    g->clear();
    for(int i =0; i < g->getCol(); i++){
        data[i] = rand()%g->getCol();
    }
    plotData();
}

// main draw function, gets called over and over, as fast as possible
void plotData(){
    if(!TRACE) g->clear();
    for(int i = 0; i < g->getCol();i++){
        g->plotPixel(i,data[i],0,0,0);

        if(i + 1 < g->getCol()) g->plotPixel(i+1,data[i],0,0,0);
        if(i - 1 >= 0) g->plotPixel(i-1,data[i],0,0,0);
        if(data[i] + 1 < g->getCol()) g->plotPixel(i,data[i]+1,0,0,0);
        if(data[i] - 1 >= 0)g->plotPixel(i,data[i]-1,0,0,0);
    }
    g->update();
    g->Sleep(SPEED);
}
