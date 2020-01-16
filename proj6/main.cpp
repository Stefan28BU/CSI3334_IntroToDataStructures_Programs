/*
 * Author:                 Yufan Xu
 * Assignment Title:       Galactic Bonding
 * Assignment Description: This program uses prompts for multiple inputs
 *                         for stimulated stars, and it will determine
 *                         whats stars are in the same constellation and
 *                         display results
 * Due Date:               04/10/2018
 * Date Created:           04/09/2018
 * Date Last Modified:     04/10/2018
 */

/*
 * Data Abstraction:
 * 		1 global variable MAX_STARS, 1 struct star and 1 class disjointSet,
 * 		    multiple types of variables including int: N, T, count1; double:
 * 		    D, X, Y, dist
 * Input:
 * 		The program reads inputs from the user: the number of text cases,
 * 		    the number of stars, a real distance, the coordinates for each
 * 		    star, then prompt again for the same content if there are more
 * 		    than 1 test case.
 * Process:
 *      The program will read the input from the user and uses the struct
 *          star and class disjointSet to determine how many constellations
 *          can be formed for each case, and then display result
 * Output:
 * 		The program generates a window to display the results for each
 * 		    test case
 * Assumptions:
 * 		Assuming the user only wants the correct results, assuming the user
 * 		    will eventually input the command that can be read as valid
 * 		    input that can generate the results
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_STARS = 1000;

//in order to set x and y coordinates, a struct star can be really helpful
struct star {
    double x, y;

    //setter function
    void setLoc(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

//disjointSet can be helpful for bonding stars together
class disjointSet{

private:
    vector<int> pset;
public:

    disjointSet(){
        pset.assign(MAX_STARS,0);
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
    disjointSet starConsl;
    int N, T;
    double D, X, Y;
    double dist;
    star Star[MAX_STARS];

    //prompt for the number of test cases
    cin >> T;

    int count1 = 1;

    //master loop for multiple test cases
    while (count1 != T+1) {

        //prompt for number of stars and real distance
        cin >> N >> D;

        //set initial number of stars
        starConsl.initSet(N);

        for (int i = 0; i < N; i ++) {

            //prompts for x and y coordinates for each star
            cin >> X >> Y;

            //set coordinates for each star
            Star[i].setLoc(X, Y);
        }

        for (int i = 0; i < N; i ++) {
            for (int j = i + 1; j < N; j++) {
                //calculates distance between two stars
                dist = sqrt(pow((Star[j].x - Star[i].x), 2) +
                            pow((Star[j].y - Star[i].y), 2));

                //bonds two stars if they are within the real distance
                if (dist < D) {
                    starConsl.unionSet(j, i);
                }
            }
        }
        cout << "Case " << count1 << ": " << starConsl.countSets(N) << endl;

        count1 ++;
    }
    return 0;
}



