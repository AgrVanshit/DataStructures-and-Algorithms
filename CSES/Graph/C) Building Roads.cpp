#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    DisjointSet ds(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ccomp = 0;
    for(int i = 1; i <= n; i++){
        for(auto it : adj[i]){
            ds.UnionBySize(i, it);
        }
    }

    vector<int> ulp;

    for(int i = 1; i <= n; i++){
        if(ds.parent[i] == i){
            ccomp++;
            ulp.push_back(i);
        }
    }

    cout << ccomp-1 << endl;

    if(ccomp - 1 != 0){
        for(size_t i = 0; i < ulp.size() - 1; i++){
            cout << ulp[i] << " " << ulp[i+1] << endl;
        }
    }
    return 0;
}