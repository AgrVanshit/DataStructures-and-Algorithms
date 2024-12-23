//*****https://leetcode.com/problems/rotate-list/description/*****


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


//T.C: O(2*len);
//S.C: O(1);
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail -> next != NULL){
            tail = tail -> next;
            len++;
        }
        if(k % len == 0) return head;
        k = k % len;
        int move = (len - k);
        ListNode* prev = head;
        int cnt = 1;
        while(cnt < move){
            prev = prev -> next;
            cnt++;
        }
        tail -> next = head;
        head = prev -> next;
        prev -> next = NULL;
        return head;
    }
};