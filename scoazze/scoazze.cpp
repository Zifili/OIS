/*// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
long long N, K;
vector<long long> C, T, Q;

vector<long long> Cbin;
long long prezzo = 0;

long long main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    C.resize(N);
    Cbin.resize(N);
    for (long long i=0; i<N; i++){
        cin >> C[i];
        Cbin[i] = 0;
    }

    T.resize(K);
    Q.resize(K);
    for (long long i=0; i<N; i++)
        cin >> T[i] >> Q[i];
    // insert your code here

    for(long long i = 0; i < K; i++){
        if(Cbin[T[i]] == C[T[i]]){
            Cbin[T[i]] = 0;
        }else{
            if(Cbin[T[i]] + Q[i] > C[T[i]]){
                prezzo += C[T[i]] - Cbin[T[i]];
                Cbin[T[i]] = 0;
            }else{
                Cbin[T[i]] += Q[i];
            }
        }
        if(i != K-1){
            for(long long n = 0; n < N; N++){
                if(Cbin[n] != 0){
                    prezzo += C[n] - Cbin[n];
                }
            }
        }
        cout << i << ": " << prezzo << endl;
    }


    cout << prezzo << endl; // prlong long the result
    return 0;
}
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
long long N, K;
vector<long long> C, T, Q;

vector<long long> Cbin;
long long prezzo = 0;

long long main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    C.resize(N);

    Cbin.resize(N);

    for (long long i=0; i<N; i++){
        cin >> C[i];
        Cbin[i] = 0;
    }

    T.resize(K);
    Q.resize(K);
    for (long long i=0; i<K; i++)
        cin >> T[i] >> Q[i];
    // insert your code here

    for(long long i = 0; i < K; i++){
        if(Cbin[T[i]] == C[T[i]]){
            Cbin[T[i]] = 0;
        }else{
            if(Cbin[T[i]] + Q[i] > C[T[i]]){
                prezzo += C[T[i]] - Cbin[T[i]];
                Cbin[T[i]] = Q[i];

            }else{
                Cbin[T[i]] += Q[i];
            }
        }
        if(i != K-1){
            for(long long n = 0; n < N; n++){
                if(Cbin[n] != 0){
                    prezzo += C[n] - Cbin[n];
                }
            }
        }
        // << i << ": " << prezzo << endl;
    }

    cout << prezzo << endl; // prlong long the result
    return 0;
}
