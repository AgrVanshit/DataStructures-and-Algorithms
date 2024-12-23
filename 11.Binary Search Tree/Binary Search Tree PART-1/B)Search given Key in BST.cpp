//*****https://leetcode.com/problems/search-in-a-binary-search-tree/description/*****


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


//Recursive Approach:
//T.C: O(log(n)) //O(n) for skew tree;
//S.C: O(log(n)) //O(n) for skew tree;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root -> val == val) return root;
        if (root -> val > val) return searchBST(root -> left, val);
        else return searchBST(root -> right, val);
    }
};


//Iterative Approach:
//T.C: O(log(n)) //O(n) for skew tree;
//S.C: O(1);
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root != NULL && root -> val != val){
            if(root -> val > val) root = root -> left;
            else root = root -> right;
        }

        return root;
    }
};