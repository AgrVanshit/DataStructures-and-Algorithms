//*****https://leetcode.com/problems/middle-of-the-linked-list/description/*****


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Bruteforce Approach:
//T.C: O(n) + O(n/2);
//S.C: O(1);
class Solution {
public:
    int linkedListLength(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp -> next;
            cnt++;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int size = linkedListLength(head);
        int midPos = (size/2) + 1;
        int cnt = 1;
        while(cnt < midPos){
            temp = temp -> next;
            cnt++;
        }
        return temp;
    }
};


//Approach 2: (Slow and Fast pointer)
//"Tortoise and the Hare" Algorithm.
//Optimal Approach:
//T.C: O(n/2);
//S.C: O(1);
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast != NULL && fast -> next != NULL){
           slow = slow -> next;
           fast = fast -> next -> next;
       }
       return slow;
    }
};