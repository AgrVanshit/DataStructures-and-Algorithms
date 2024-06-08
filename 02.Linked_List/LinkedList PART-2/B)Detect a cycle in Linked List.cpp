//*****https://leetcode.com/problems/linked-list-cycle/description/*****


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Bruteforce Approach:
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp[temp] != 0) return true;
            mpp[temp]++;
            temp = temp -> next;
        }
        return false;
    }
};


//Optimal Approach:("Tortoise and the Hare" Algorithm)
//T.C: O(n);
//S.C: O(1);
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }
        return false;
    }
};