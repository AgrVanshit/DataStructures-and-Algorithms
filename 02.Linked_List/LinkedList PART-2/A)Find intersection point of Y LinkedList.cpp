//*****https://leetcode.com/problems/intersection-of-two-linked-lists/description/*****


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
//Bruteforce Approach:
//T.C: O(n1 + n2); // n -> length of list.
//S.C: O(n1) OR O(n2);
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mpp;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != NULL){
            mpp[tempA]++;
            tempA = tempA -> next;
        }

        while(tempB != NULL){
            if(mpp[tempB] != 0) return tempB;
            tempB = tempB -> next;
        }
        return NULL;
    }
};


//Better Approach:
//T.C: O(n1) + O(n2) + O(max(n1, n2)); // n -> length of list.
//S.C: O(1);
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int cntA = 0, cntB = 0;
        while(tempA != NULL || tempB != NULL){
            if(tempA != NULL){
                cntA++;
                tempA = tempA -> next;
            }
            if(tempB != NULL){
                cntB++;
                tempB = tempB -> next;
            }
        }

        tempA = headA;
        tempB = headB;

        int diff = abs(cntA - cntB);


        while(diff--){
            if(cntA > cntB) tempA = tempA -> next;
            else tempB = tempB -> next;
        }

        while(tempA != NULL){
            if(tempA == tempB) return tempA;
            tempA = tempA -> next;
            tempB = tempB -> next;
        }
        return NULL;
    }
};


//Optimal Approach:
//T.C: O(n1 + n2); // n -> length of list.
//S.C: O(1);
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){
            if(tempA == NULL) tempA = headB;
            else tempA = tempA -> next;

            if(tempB == NULL) tempB = headA;
            else tempB = tempB -> next;
        }
        return tempA;
    }
};
