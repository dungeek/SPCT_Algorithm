/*
Problem:
Given an sorted array A(N) in increasing order (N <= 5e7)
Given a number K. 
Print out true if at least a pair of number (i,j) exists, which A[i] + A[j] = K. Or print -1 if not possible to find such that i,j

*/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for(int i = 0; i < N; i++) cin >> A[i];

    //Init 2 pointers
    int st = 0, en = N - 1;

    while (st <= en)
    {
        long long sum = A[st] + A[en]; //Prevent overflow
        if(sum == K){
            return true;
        }else if(sum < K){
            st++; //Move ptr to right
        } else {
            en--; //move ptr to left 
        }
    }

    return 0;
}