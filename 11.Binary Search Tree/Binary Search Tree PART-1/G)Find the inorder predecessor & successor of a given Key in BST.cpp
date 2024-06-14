//*****https://www.geeksforgeeks.org/problems/predecessor-and-successor/1*****


/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/


//Iterative Approach:
//T.C: 2*O(log(n));
//S.C: O(1);
class Solution
{
    public:
    Node* prede(Node *root,int key){
        Node* ans = NULL;
        Node * curr = root;

        while(curr != NULL){
            if(curr -> key >= key) curr = curr -> left;
            else {
                ans = curr;
                curr = curr -> right;
            }
        }

        return ans;
    }

    Node* succ(Node *root,int key){
        Node* ans = NULL;
        Node*curr = root;

        while(curr != NULL){
            if(curr -> key > key){
                ans = curr;
                curr = curr -> left;
            }
            else curr = curr -> right;
        }

        return ans;
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = prede(root,key);
        suc = succ(root,key);
    }
};