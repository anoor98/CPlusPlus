#include <iostream>
#include <string>
using namespace std;

bool sum_top(int a[], int n, int m, int & sum) {
    if(m <= 0 || n <= 0 || m > n){
        int max = sum;
        sum = 0;
        sum += max;
        return false;
    }
    
    int max = sum; // max = (previous instance's) largest number. Initially 0, it will later carry largest #.
    sum = 0; // I don't know what sum is initialized to so I force set it to 0. Becomes current largest #.
    
    if(max != 0){
        for(int i = 0; i < n; i++){
            if(a[i] > sum && a[i] < max){
                sum = a[i]; // max = largest # that doesn't equal previous largest number.
            }
        }
    }
    else
        for(int i = 0; i < n; i++){
            if(a[i] > sum){
                sum = a[i]; // max = largest # that doesn't equal previous largest number.
            }
        }
    sum_top(a, n, m-1, sum);
    sum += max;
    return true;
}