//*****https://leetcode.com/problems/set-matrix-zeroes/description/*****

//Bruteforce Approach:
//T.C : O(n*m*(n+m)) + O(n*m);
//S.C : O(n*m)
class Solution {
public:
    int n, m;
    void setrow(int i, vector<vector<int>>& matrix){
        for(int k = 0; k < m; k++){
            matrix[i][k] = 0;
        }
    }
    void setcol(int j, vector<vector<int>>& matrix){
        for(int k = 0; k < n; k++){
            matrix[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<char>> dummy(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool row = false, col = false;
                for(int k = 0; k < m; k++){
                    if(matrix[i][k] == 0) row = true;
                }
                for(int k = 0; k < n; k++){
                    if(matrix[k][j] == 0) col = true;
                }
                if(row == true && col == true) dummy[i][j] = 'b';
                else if(row == true) dummy[i][j] = 'r';
                else if(col == true) dummy[i][j] = 'c';
                else dummy[i][j] = 'x';
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dummy[i][j] == 'x') continue;
                else if(dummy[i][j] == 'b'){
                    setrow(i, matrix);
                    setcol(j, matrix);
                }
                else if(dummy[i][j] == 'r') setrow(i, matrix);
                else if(dummy[i][j] == 'c') setcol(j, matrix);
            }
        }
    }
};


//Better Approach:
//T.C : O(2*n*m)
//S.C : O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    col[j] = 1;
                    row[i] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(col[j] == 1 || row[i] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//Optimized Approach:
//T.C : O(2*n*m)
//S.C : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // vector<int> row(n, 0); // matrix[0][i]
        // vector<int> col(m, 0); // matrix[i][0]

        int col0 = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    //Treating col1 as dummy row(n, 0) used in prev approach....
                    matrix[i][0] = 0;

                    //Treating row1 as dummy col(m, 0) used in prev approach....
                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] != 0) if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};