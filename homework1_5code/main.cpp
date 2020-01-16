#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void loop1(int n);
void loop2();
void loop3();
void loop4();

void loop5();
void loop6();

int main() {

    int n = 160;
    unsigned int start, stop;

    int count = 0;
    start = clock();
    while (clock() - start <= 2000) {
        loop1(n);
        count++;
    }
    stop = clock();
    cout << static_cast<double>(stop - start)/ count<< endl;
}

void loop1(int n){
    int sum = 0;
    for (int i = 0;i < n; ++i) {
        for (int j = 0; j < i*i; ++j) {
            if (j % i == 0) {
                for (int k = 0; k < j; ++k) {
                    ++sum;
                }
            }
        }
    }
}

void loop2(){
    clock_t start = clock();
    double sum = 0.0;
    int n = 8;
    for (int i = 0;i < n; ++i) {
        for(int j = 0; j <n; ++j) {
            ++sum;
        }
    }
    clock_t end = clock();
    cout << fixed << setprecision(10);
    cout << static_cast<double>(end - start) /CLOCKS_PER_SEC << endl;
}

void loop3(){
    clock_t start = clock();
    double sum = 0.0;
    int n = 40;
    for (int i = 0;i < n; ++i) {
        for(int j = 0; j <n*n; ++j) {
            ++sum;
        }
    }
    clock_t end = clock();
    cout << fixed << setprecision(10);
    cout << static_cast<double>(end - start) /CLOCKS_PER_SEC << endl;
}

void loop4(){
    clock_t start = clock();
    double sum = 0.0;
    int n = 400;
    for (int i = 0;i < n; ++i) {
        for(int j = 0; j <i; ++j) {
            ++sum;
        }
    }
    clock_t end = clock();
    cout << fixed << setprecision(10);
    cout << static_cast<double>(end - start) /CLOCKS_PER_SEC << endl;
}


void loop5(){
    clock_t start = clock();
    double sum = 0.0;
    int n = 40;
    for (int i = 0;i < n; ++i) {
        for(int j = 0; j <i*i; ++j) {
            for(int k = 0; k <j;++k) {
                ++sum;
            }
        }
    }
    clock_t end = clock();
    cout << fixed << setprecision(10);
    cout << static_cast<double>(end - start) /CLOCKS_PER_SEC << endl;
}

void loop6(){
    clock_t start = clock();
    double sum = 0.0;
    int n = 40;
    for (int i = 0;i < n; ++i) {
        for(int j = 0; j <i*i; ++j) {
            if(j%i==0) {
                for (int k = 0; k < j; ++k) {
                    ++sum;
                }
            }
        }
    }
    clock_t end = clock();
    cout << fixed << setprecision(10);
    cout << static_cast<double>(end - start) /CLOCKS_PER_SEC << endl;
}