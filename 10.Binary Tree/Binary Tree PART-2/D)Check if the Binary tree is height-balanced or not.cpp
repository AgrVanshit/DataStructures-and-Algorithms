//*****https://leetcode.com/problems/balanced-binary-tree/description/*****


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


/*FOR BINARY TREE TO BE BALANCED DIFFERENCE BETWEEN 
  LEFT HEIGHT AND RIGHT HEIGHT AT ALL THE NODES SHOULD 
  BE LESS THAN OR EQUAL TO ONE (<= 1).
*/

/*Bruteforce Approach 1:(Using preorder traversal 
                       and whenever we reach any 
                       node just calculating the 
                       diameter and finding the 
                       maximum). */
//T.C: O(n*n);
//S.C: O(n);
class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        return 1 + max(lh, rh);
    }
    bool preorder(TreeNode* root){
        if(root == NULL) return true;

        int lh = height(root -> left);
        int rh = height(root -> right);
        
        if(abs(lh - rh) > 1) return false;

        bool left = preorder(root -> left);
        bool right = preorder(root -> right);

        return left & right;
    }
    bool isBalanced(TreeNode* root) {
        return preorder(root);
    }
};


/*Bruteforce Approach 2:(Using preorder traversal 
                       and whenever we reach any 
                       node just calculating the 
                       diameter and finding the 
                       maximum). */
/*Same as Approach 1 just not using extra function for
  preorder, doing it in the same given function.*/
//T.C: O(n*n);
//S.C: O(n);
class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        if(abs(lh - rh) > 1) return false;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(left == false || right == false) return false;

        return true;
    }
};


//Optimal Approach:
//*****Using find height Approach*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfsHeight(root -> left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root -> right);
        if(rh == -1) return -1;

        if(abs(lh-rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};