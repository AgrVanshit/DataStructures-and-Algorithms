//*****https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM*****


//Bruteforce Approach:
// T.C: O(n*n);
// S.C: O(1);
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[i]) cnt++;
        }
    }
    return cnt;
}


//Optimal Approach:(Modification in merge sort)
// T.C: O(nlogn);
// S.C: O(n);
/*In an interview we should tell that we are distorting the 
  data i.e the given array, if an interviewer does not want us
  to distort the given data we can form the copy of an array
  initially and then solve the problem. */
#include <bits/stdc++.h> 

long long merge(long long *arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    long long cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

long long mergeSort(long long *arr, int low, int high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Count the number of pairs:
    return mergeSort(arr, 0, n - 1);
}