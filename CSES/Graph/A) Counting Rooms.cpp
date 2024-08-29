#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& arr){
    vis[i][j] = 1;

    int delrow[] = {1, 0, -1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        int nrow = i + delrow[k];
        int ncol = j + delcol[k];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == '.'){
            dfs(nrow, ncol, n, m, vis, arr);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && arr[i][j] == '.'){
                cnt++;
                dfs(i, j, n, m, vis, arr);
            }
        }
    }

    cout << cnt;
}