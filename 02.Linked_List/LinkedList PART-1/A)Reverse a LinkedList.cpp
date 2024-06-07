//*****https://leetcode.com/problems/reverse-linked-list/description/*****


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
/* Iterate in linked list, store each value in stack
   and then again iterate and assign top value of stack 
   to each linked list node and pop the top value after 
   each assignment */

//Optimal Approach 1:   
//Iterative Approach
//T.C: O(n);
//S.C: O(1);
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head != NULL){
            ListNode* next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};


//Optimal Approach 2:
//Recursive Approach:
//T.C: O(n);
//S.C: O(n);(Recursive stack space)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
};