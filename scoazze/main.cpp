#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N, K;
vector<int> C, T, Q;

vector<int> Cbin;
int prezzo = 0;

int main() {
  //  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
  //  ofstream cout("output.txt");

  cin >> N >> K;
  C.resize(N);

  Cbin.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> C[i];
    Cbin[i] = 0;
  }

  T.resize(K);
  Q.resize(K);
  for (int i = 0; i < K; i++)
    cin >> T[i] >> Q[i];
  // insert your code here

  for (int i = 0; i < K; i++) {
    if (Cbin[T[i]] == C[T[i]]) {
      Cbin[T[i]] = 0;
    } else {
      if (Cbin[T[i]] + Q[i] > C[T[i]]) {
        prezzo += C[T[i]] - Cbin[T[i]];
        Cbin[T[i]] = Q[i];
      } else {
        Cbin[T[i]] += Q[i];
      }
    }
    cout << i << "a: " << prezzo << endl;
    if (i == K - 1) {
      for (int n = 0; n < N; n++) {
        if (Cbin[n] != 0) {
          prezzo += C[n] - Cbin[n];
          // cout << i << "c: " << prezzo << "n " << n << endl;
        }
      }
    }
    cout << i << "b: " << prezzo << endl;
  }

  cout << prezzo << endl; // print the result
  return 0;
}
