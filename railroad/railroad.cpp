#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;
struct arco;
class nodo;


class nodo {
    public:
    vector<arco> adiacenti;
    int peso = INT_MAX;
    nodo* prev;
};

struct arco {
    nodo* arrivo;
    int peso;
};

int dijkstra(vector<nodo*> grafo) {
    int N = grafo.size();
    priority_queue<pair<int, nodo*>, vector<pair<int, nodo*> >, greater<pair<int, nodo*> > > Q;

    Q.push(make_pair(0, grafo[0]));

    while (!Q.empty())
    {
        nodo* n = Q.top().second;
        Q.pop();
        if (n == grafo[N-1])
        {
            return n->peso;
        }
        for (auto &arc: n->adiacenti)
        {
            if (arc.arrivo->peso > n->peso+arc.peso) {
                arc.arrivo->peso = n->peso+arc.peso;
                Q.push(make_pair(arc.arrivo->peso, arc.arrivo));
                arc.arrivo->prev = n;
            }
        }
    }
    return -1;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
    // ifstream cin("input1.txt");
    //  ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<nodo*> grafo(N);
    set<nodo*> nodi;
    for (int i = 0; i < N; i++) {
        grafo[i] = new nodo();
        nodi.insert(grafo[i]);
    }

    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    for (int i = 0; i < M; i++)
    {
        arco arc;
        arc.peso = C[i];
        arc.arrivo = grafo[B[i]];
        grafo[A[i]]->adiacenti.push_back(arc);
        arc.arrivo = grafo[A[i]];
        grafo[B[i]]->adiacenti.push_back(arc);
    }
    
    grafo[0]->peso = 0;

    int total = dijkstra(grafo);

    nodo* p = grafo[N-1];
    while (p != NULL)
    {
        nodi.erase(p);
        p = p->prev;
    }
    
    int r = INT_MAX;

    for (auto &n : nodi)
    {
        for (auto &arc : n->adiacenti)
        {
            int bak = arc.peso;
            arc.peso = 1;
            arco* opposto;
            for (auto &aaaaa : arc.arrivo->adiacenti)
            {
                if (aaaaa.arrivo == n) {
                    opposto = &aaaaa;
                    break;
                }
            }
            opposto->peso = 1;
            
            int nuovo = INT_MAX;
            while (1==1)
            {
                for (auto &node : grafo)
                {
                    node->peso = INT_MAX;
                }
                grafo[0]->peso = 0;
                int nn = dijkstra(grafo);
                if (nn < total) {
                    nuovo = nn;
                } else {
                    break;
                }
                arc.peso++;
                opposto->peso++;
            }
            if (bak-(arc.peso-1) < r && nuovo<total) {
                r = bak-(arc.peso-1);
            }
            arc.peso = bak;
            opposto->peso = bak;
        }
        
    }
    
    if (r == INT_MAX)
    {
        r = -1;
    }
    cout << r << endl; // print the result

    return 0;
}