//*****https://leetcode.com/problems/rotate-image/description/*****


//Bruteforce Approach:
//T.C: O(n*n);
//S.C: O(n*n);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy = matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[j][n-1-i] = dummy[i][j];
            }
        }
    }
};


//Optimised Approach: 1)Transpose the given matrix.
//                    2)Reverse each row.
//T.C: O((n/2)*(n/2)) + O(n*(n/2));
//S.C: O(1);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //Finding Transpose: T.C: O((n/2)*(n/2))
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reversing each row: T.C: O(n*(n/2))
        /*we can also use two pointer approach to reverse an 
          array, it takes O(n/2) time complexity.*/
        for(auto &it : matrix){
            reverse(it.begin(), it.end());
        }
    }
};