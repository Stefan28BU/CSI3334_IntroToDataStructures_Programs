/*
 * Author:                 Yufan Xu
 * Assignment Title:       Racing
 * Assignment Description: This program prompts for multiple inputs
 *                         for and it will calculate the minimum costs
 *                         for placing cameras around the circuit
 * Due Date:               04/29/2018
 * Date Created:           04/28/2018
 * Date Last Modified:     04/29/2018
 */

/*
 * Data Abstraction:
 * 		1 global variable MAX, 1 struct CASE and 1 class disjointSet,
 * 		    multiple types of variables including int, vector, disjointSet,
 * 		    CASE
 * Input:
 * 		The program reads inputs from the user: the number of text cases,
 * 		    the number of vertices and edges, then the start and end
 * 		    vertex and weight of each path and a zero at the end
 * Process:
 *      The program will read the input from the user and uses the struct
 *          CASE and class disjointSet to determine the least cost for
 *          placing cameras on a race track
 * Output:
 * 		The program generates a window to display the results of total
 * 		    cost needed
 * Assumptions:
 * 		Assuming the user only wants the correct results, assuming the user
 * 		    will eventually input the command that can be read as valid
 * 		    input that can generate the results
 */

#include <iostream>
#include <vector>

using namespace std;

int const MAX = 10000;

struct CASE {
    int p1, p2, w;
    void setNum(int p1, int p2, int w) {
        this->p1 = p1;
        this->p2 = p2;
        this->w = w;
    }
};

class disjointSet{

private:
    vector<int> pset;
public:

    disjointSet(){
        pset.assign(MAX,0);
    }

    void initSet(int N ){

        for(int i = 0; i < N; i++)
            pset[i] = i;
    }

    int findSet(int i){
        if (pset[i] == i)
            return i;
        else
            return (pset[i]=findSet(pset[i]));
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        pset[findSet(i)] = findSet(j);
    }

    int countSets(int N){
        int count = 0;

        for(int i = 0; i < N; i++){
            if(pset[i] == i) count++;
        }

        return count;
    }
};

//main function
int main() {

    //initializing variables
    disjointSet set1;
    int c, n, m, d1, d2, d3, end;
    int count = 0;
    int num;
    int addN;
    int total = 0;
    CASE s[MAX];

    //prompt for number of cases
    cin >> c;

    while (count != c) {

        //prompt for number of vertices and edges
        cin >> n >> m;

        //intialize disjoint set
        set1.initSet(m);

        //calc minimum camera required
        addN = n/3;

        //prompt for start and end point as well as
        //for the weight for each edge
        for (int i = 0; i < m; i ++) {
            cin >> d1 >> d2 >> d3;

            //set numbers to struct
            s[i].setNum(d1, d2, d3);
        }

        //sort weight
        for (int i = 0; i < m-1; i ++) {
            for (int j = 0; j < m-i-1; j ++) {
                if (s[j].w > s[j+1].w) {
                    num = s[j].w;
                    s[j].w = s[j+1].w;
                    s[j+1].w = num;
                }
            }
        }

        //calc total
        for (int i = 0; i < addN; i ++) {
            total += s[i].w;
        }

        cin >> end;

        cout << total << endl;

        count ++;
    }
    return 0;
}