//*****https://leetcode.com/problems/diameter-of-binary-tree/description/*****


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


//Bruteforce Approach:
//T.C: O(n*n);
//S.C: O(n);
class Solution {
public:
    int dia = 0;
    
    int findH(TreeNode* root){
        if(root == NULL) return 0;

        int lh = findH(root -> left);
        int rh = findH(root -> right);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = findH(root -> left);
        int rh = findH(root -> right);

        dia = max(dia, lh + rh);

        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree(root -> right);

        return dia;
    }
};


//Optimal Approach:
//*****Using find height Approach*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    int height(TreeNode* root, int& dia){
        if(root == NULL) return 0;

        int lh = height(root -> left, dia);
        int rh = height(root -> right, dia);

        dia = max(dia, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        if(root == NULL) return 0;
        height(root, dia);
        return dia;
    }
};