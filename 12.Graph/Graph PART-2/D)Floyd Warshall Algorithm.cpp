//*****https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1*****


//FLOYD WASHALL ALGORITHM:
//Multiple source shortest path Algorithm.
//Helps to detect negative cycle as well.
//T.C: O(n * n * n);
//S.C: O(n * n);
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(matrix[i][j] == -1){
					matrix[i][j] = 1e9;
				}
				if(i == j) matrix[i][j] = 0;
			}
		}

        //These three loops are implementing Floyd Warshall Algorithm.
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == 1e9){
					matrix[i][j] = -1;
				}
			}
		}
	}
};


/*To check if graph has a negative cycle, if the diag element in the matrix 
  becomes negative after applying the algorithm means the graph has negative 
  cycle, diagonal element means we have reached from any node to the same node 
  and if it becomes negative means graph has negative cycle.
  CODE: 
       for(int i = 0; i < n; i++){
           if(matrix[i][i] < 0){
              //Graph has negative cycle.
           }
       } 
*/


/* Dijkstra's Algorithm can also be used to find multi source shortest path, 
   but we are not using here beacause we initially don't know that graph has 
   a negative cycle or not, if graph has a negative cycle and we use Dijkstra's 
   algorithm we get TLE, so for finding multi source shortest path we can use 
   Dijkstra's algorithm on each node only if we already know that graph does 
   not have a negative cycle. */


//Related Ques: 
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/