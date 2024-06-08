//*****https://leetcode.com/problems/linked-list-cycle-ii/description/*****


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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp[temp] != 0) return temp;
            mpp[temp]++;
            temp = temp -> next;
        }
        return NULL;
    }
};


//Optimal Approach:
//T.C: O(n);
//S.C: O(1);
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                while(slow != entry){
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
