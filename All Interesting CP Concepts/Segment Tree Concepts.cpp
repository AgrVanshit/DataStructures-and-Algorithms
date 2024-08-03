//*******************************SEGMENT TREE*************************************


//RANGE SUM QUERY:
//https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
//T.C : O(q * log(n));
//S.C : O(4 * n);
//Main function is querysum function:
class Solution{
public:
    void buildsegtree(int i, int l, int r, vector<int>& segtree, int arr[]){
        if(l == r){
            segtree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        buildsegtree(2*i + 1, l, mid, segtree, arr);
        buildsegtree(2*i + 2, mid+1, r, segtree, arr);
        
        segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
    }
    
    int Query(int start, int end, int i, int l, int r, vector<int>& segtree){
        if(l > end || r < start){
            return 0;
        }
        if(l >= start && r <= end){
            return segtree[i];
        }
        
        int mid = l + (r-l)/2;
        
        return Query(start, end, 2*i + 1, l, mid, segtree)
              + Query(start, end, 2*i + 2, mid + 1, r, segtree);
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> segtree(4 * n);
        
        buildsegtree(0, 0, n-1, segtree, arr);
        vector<int> res;
        
        for(int i = 0; i < 2*q; i += 2){
            int start = queries[i] - 1;
            int end = queries[i+1] - 1;
            
            res.push_back(Query(start, end, 0, 0, n-1, segtree));
        }
        
        return res;
    }
};


//RANGE MINIMUM QUERY:
//https://www.geeksforgeeks.org/problems/range-minimum-query/1
//T.C : O(q * log(n));
//S.C : O(4 * n);
void buildsegtree(int i, int l, int r, int *segtree, int arr[]){
    if(l == r){
        segtree[i] = arr[l];
        return;
    }
    
    int mid = l + (r - l)/2;
    buildsegtree(2*i + 1, l, mid, segtree, arr);
    buildsegtree(2*i + 2, mid + 1, r, segtree, arr);
    
    segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}
/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n){
  int* segtree = new int[4 * n];
  buildsegtree(0, 0, n-1, segtree, arr);
  
  return segtree;
}


int Query(int start, int end, int i, int l, int r, int st[]){
    if(l > end || r < start){
        return INT_MAX;
    }
    if(l >= start && r <= end){
        return st[i];
    }
    
    int mid = l + (r-l)/2;
    return min(Query(start, end, 2*i + 1, l, mid, st), Query(start, end, 2*i + 2, mid + 1, r, st));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b){
    return Query(a, b, 0, 0, n-1, st);
}


//RANGE UPDATE:
//LAZY PROPAGATION:
//T.C : O(q * log(n));
//S.C : O(4 * n) + O(4 * n);
//NOTE - Below is just the function for updateRange
//i.e. For each query, we are asked to update values of nodes in range [start....end]
//Assuming we have defined segmentTree[4*n] and lazyTree[4*n]
void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) { //Not a leaf node
            lazyTree[i * 2 + 1] += lazyTree[i]; //Left Child in Lazy Tree
            lazyTree[i * 2 + 2] += lazyTree[i]; //Right Child in Lazy tree
        }
        
        lazyTree[i] = 0;
    }

    //Invalid or out of range
    if (l > end || r < start || l > r)
        return;

    //[start...end[ is Exactly withing range of current nod [l..r]
    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        
        return;
    }

    //Call for left and right subtree
    int mid = (l + r) / 2;

    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);

    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];
}



//PRACTICE QUESTIONS:
//https://leetcode.com/problems/range-sum-query-mutable/description/