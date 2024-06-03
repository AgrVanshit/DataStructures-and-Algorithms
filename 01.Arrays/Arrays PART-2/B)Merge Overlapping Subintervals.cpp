//*****https://leetcode.com/problems/merge-intervals/description/*****


//Bruteforce Approach:
//T.C: O(n*n) + O(nlogn);
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = intervals.size(); 

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};


//Better Approach:
//T.C: O(n) + O(nlogn);
//S.C: O(n);
//(My Attempt(Accepted), Using temp array);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int first = intervals[0][0], second = intervals[0][1];
        vector<int> temp;
        if(n == 1) return intervals;
        temp.push_back(first);

        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= second){
                second = max(intervals[i][1], second);
            }
            else{
                temp.push_back(second);
                ans.push_back(temp);
                first = intervals[i][0];
                second = intervals[i][1];
                temp.clear();
                temp.push_back(first);
            }
        }
        ans.push_back({first, second});

        return ans;
    }
};


//Optimised Approach:(Without temp array)
//T.C: O(n) + O(nlogn);
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1; i<intervals.size() ; i++){
            if(intervals[i][0] <= end) 
                end = max(end , intervals[i][1]);
            else{
                ans.push_back({start , end});
                
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start , end});
        
        return ans;
        
    }
};


//Optimised Approach:(More Readable)
//T.C: O(n) + O(nlogn);
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            /*If ans is empty then also we are pushing 
              and we will update in the else case if we
              find an overapping interval*/
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};