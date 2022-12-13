// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N, M, K, Q;
vector<int> PA, PB, X, Y, C, U, V;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    PA.resize(N-1);
    for(int i = 0; i < N-1; i++){
        cin >> PA[i];
    }
    cin >> M;
    PB.resize(M-1);
    for(int i = 0; i < M-1; i++){
        cin >> PB[i];
    }
    cin >> K;
    X.resize(K);
    Y.resize(K);
    C.resize(K);
    for(int i = 0; i < K; i++){
        cin >> X[i] >> Y[i] >> C[i];
    }
    cin>>Q;
    U.resize(Q);
    V.resize(Q);
    for(int i = 0; i < Q; i++){
        cin >> U[i] >> V[i];
    }
    // insert your code here

    cout << 42 << endl; // print the result
    return 0;
}
