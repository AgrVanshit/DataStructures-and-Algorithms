//*****https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/*****


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


/*The most naive solution will be to do any traversal be it inorder, 
  preorder or postorder, store it in the vector, sort the vector and 
  return the kth smallest element from that vector */


//Bruteforce Approach:
//T.C: O(n);
//S.C: O(n) + O(n);
class Solution {
public:
    void iterate(TreeNode* root, vector<int>& v){
        if(root == NULL) return;

        iterate(root -> left, v);
        v.push_back(root -> val);
        iterate(root -> right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        iterate(root, v);
        return v[k-1];
    }
};


//Optimized Approach:
//T.C: O(n);
//S.C: O(n); //For recursive stack space.
class Solution {
public:
    void iterate(TreeNode* root, int &cnt, int &ans, int &k){
        if(root == NULL) return;

        iterate(root -> left, cnt, ans, k);
        cnt++;
        if(cnt == k) ans = root -> val;
        iterate(root -> right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;
        iterate(root, cnt, ans, k);
        return ans;
    }
};


/* If we use Morris traversal in place of recursive traversal 
   the code will be more optimized as it would not take extra 
   space complexity i.e recursive stack space and hence space 
   complexity will be reduce to constant */