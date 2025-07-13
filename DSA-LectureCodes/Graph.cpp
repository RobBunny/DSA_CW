#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:    
    Graph(int n){
        this->V = n;
        adj = new vector<int>[n];
    }
    void addEdge(int u, int v) {
        if(u<V && v<V && u>0 && v>0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void BFS(int s) {
        queue<int> q;
        vector<bool> isVisited(V, false);
        q.push(s);
        isVisited[s] = true;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int i = 0; i < adj[current].size(); i++) {
                if (!isVisited[adj[current][i]]) {
                    isVisited[adj[current][i]] = true;
                    q.push(adj[current][i]);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printGraph();
    g.BFS(1);
    return 0;  
}