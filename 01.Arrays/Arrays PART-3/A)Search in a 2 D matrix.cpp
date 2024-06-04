//*****https://leetcode.com/problems/search-a-2d-matrix/description/*****


//Bruteforce solution:
//T.C: O(n*m);
//S.C: O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};


/*Better solution 1:(Applying binary search on a row in which 
                   there is possibility of finding a target)*/
//T.C: O(m) + O(log(n));
//S.C: O(1);
class Solution {
public:
    bool bs(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target) return true;
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(target >= matrix[i][0] && target <= matrix[i][n-1]){
                if(bs(matrix[i], target)) return true;
                return false;
            }
        }
        return false;
    }
};


//Better solution 2:
//T.C: O(m+n);
//S.C: O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        while(j>=0 && i<n){
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};


//Optimal solution:(Flattening a 2-D Matrix)
//T.C: O(log(m*n));
//S.C: O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m = matrix.size();
        /*Keep in mind that n is no. of columns here,
          not number of rows.*/
        int n = matrix[0].size();
        int low=0;
        int high=n*m - 1;

         while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
         }
         return false;
    }
};