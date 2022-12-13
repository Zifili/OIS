#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;
int solve(int n);

int main() {
    // ifstream cin("input.txt");
    int N, a;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        cout << solve(a) << endl;
    }
}

int solve(int n) {
    set<char>Seen;
    int i;
    for (i = 1; Seen.size() < 10; i++)
    {
        string s = to_string(n*i);
        for (int j = 0; j < s.length(); j++) {
            Seen.insert(s[j]);
        }
    }
    return i-1;
}