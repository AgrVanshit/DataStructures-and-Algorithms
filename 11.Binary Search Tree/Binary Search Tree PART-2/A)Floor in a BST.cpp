//*****https://www.geeksforgeeks.org/problems/floor-in-bst/0*****


//Recursive Approach:
//T.C: O(log(n));
//S.C: O(log(n));
class Solution{
public:
    void help(Node* root , int target , int &ans){
        if(root== NULL) return ;
        
        if(root->data == target){
            ans = target;
            return;
        }
        else if(root->data < target){
            ans  = root -> data;
            help(root->right , target,ans);
        }
        else{
            help(root->left, target,ans);
        }
    }
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
        int ans = -1;
        help(root, x , ans);
        return ans;
    }
};


//Iterative Approach:
//T.C: O(log(n));
//S.C: O(1);
class Solution{
public:
    int floor(Node* root, int x) {
        int floor = -1;
        if (root == NULL) return -1;
        
        while(root != NULL){
            if(root -> data == x){
                floor = root -> data;
                return floor;
            }
            if(root -> data < x){
                floor = root -> data;
                root = root -> right;
            }
            else root = root -> left;
        }
        
        return floor;
    }
};
