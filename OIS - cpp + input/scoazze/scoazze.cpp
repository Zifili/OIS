// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N, K;
vector<int> C, T, Q;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    C.resize(N);
    for (int i=0; i<N; i++)
        cin >> C[i];

    T.resize(K);
    Q.resize(K);
    for (int i=0; i<N; i++)
        cin >> T[i] >> Q[i];
    // insert your code here

    cout << 42 << endl; // print the result
    return 0;
}
