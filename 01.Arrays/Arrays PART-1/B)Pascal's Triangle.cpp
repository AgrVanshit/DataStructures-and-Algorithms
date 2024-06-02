//*****https://leetcode.com/problems/pascals-triangle/description/*****

/*
Type-1: Given r and c (both 1 indexed), find the element at the rth row and cth column in Pascal's triangle....
Answer : (r-1)C(c-1)

-For finding nCr i.e n!/r!(n-r)! we can find individual factorials, but optimized code is-
-Function to find nCr....
    int findnCr(n, r){
        long long res = 0;
        for(int i = 0; i < r; i++){
            res *= n-i;
            res /= i+1;
        }
        return res;
    }
    T.C: O(r)
*/

/*
Type-2: Given n, print nth row....

int print(n){
    int ans = 1;
    //Printed first element....
    cout << ans << " ";
    //Came to this loop after seeing pattern in each row....
    for(int i = 1; i < n; i++){
        ans *= n-i;
        ans /= i;

        cout << ans << " ";
    }
}
T.C: O(n)
*/


//Type-3: Given n, Print the Pascal's triangle upto nth row....

// Bruteforce Approach:(Finding each element and pushing)
//TC : O(n*n*r) + O(r);
//S.C : O(n*n) + O(n);
class Solution {
public:
    int findnCr(int n, int r){
        int res = 1;
        for(int i = 0; i < r; i++){
            res *= n-i;
            res /= i+1;
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            for(int j = 1; j <= i; j++){
                temp.push_back(findnCr(i-1, j-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//Optimized Approach 1 (Not a Generalised one):
// T.C: O(n*(n+1)/2);
// S.C : O(n) + O(n) + O(n*n) (here O(n*n) used just for returning answer)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<int> temp, curr;
        vector<vector<int>> ans;

        temp.push_back(1);
        ans.push_back(temp);
        if(n == 1) return ans;

        for(int i = 0; i < temp.size(); i++){

            if(i == 0) curr.push_back(1);
            else curr.push_back(temp[i] + temp[i-1]);

            if(i == temp.size()-1){
                curr.push_back(1);
                ans.push_back(curr);
                if(ans.size() == n) break;
                i = -1;
                temp = curr;
                curr.clear();
            }

        }
        return ans;
    }
};


//Optimal Approach 2:(Generating each row and pushing in ans vector)
//T.C: O(n*n);
//S.C: O(n*n) -> Not for solving, just for returning the answer.
class Solution {
public:
    //Function Generating each row....
    vector<int> generateRow(int row){
        vector<int> ansRow;
        ansRow.push_back(1);
        int res = 1;
        for(int col = 1; col < row; col++){
            res *= row-col;
            res /= col;
            ansRow.push_back(res);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        
        for(int i = 1; i <= n; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
