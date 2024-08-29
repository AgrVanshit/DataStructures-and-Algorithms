#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<pair<int, int>>> &parent, vector<vector<int>> &dis, vector<vector<char>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    dis[i][j] = 0; // Initialize the source distance to 0
    pq.push({0, {i, j}});

    while (!pq.empty())
    {
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        if (arr[row][col] == 'B')
            break;

        int dist = pq.top().first;
        pq.pop();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m)
                continue;

            if (arr[nrow][ncol] == '#')
                continue;

            if (dist + 1 < dis[nrow][ncol])
            {
                dis[nrow][ncol] = dist + 1;
                pq.push({dist + 1, {nrow, ncol}});
                parent[nrow][ncol] = {row, col};
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int srci = -1, srcj = -1;
    int tari = -1, tarj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'B')
            {
                tari = i;
                tarj = j;
            }
            if (arr[i][j] == 'A')
            {
                srci = i;
                srcj = j;
                solve(i, j, parent, dis, arr);
            }
        }
    }

    if (dis[tari][tarj] == INT_MAX)
    {
        cout << "NO";
        return 0;
    }

    int row = tari;
    int col = tarj;
    vector<pair<int, int>> path;

    while (parent[row][col].first != -1 && parent[row][col].second != -1)
    {
        path.push_back({row, col});
        int prevRow = parent[row][col].first;
        int prevCol = parent[row][col].second;
        row = prevRow;
        col = prevCol;
    }
    path.push_back({srci, srcj});
    reverse(path.begin(), path.end());

    string s = "";

    for(int i = 1; i < path.size(); i++){
        int r = path[i].first;
        int c = path[i].second;
 
        if(r - srci == 1){
            s.push_back('D');
        }
        if(r - srci == -1){
            s.push_back('U');
        }
        if(c - srcj == 1){
            s.push_back('R');
        }
        if(c - srcj == -1){
            s.push_back('L');
        }
 
        srci = r;
        srcj = c;
    }

    cout << "YES" << endl;
    cout << dis[tari][tarj] << endl;
    cout << s << endl;

    return 0;
}