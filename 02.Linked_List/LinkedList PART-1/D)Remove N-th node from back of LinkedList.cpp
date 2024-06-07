//*****https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/*****


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
//T.C: O(length) + O(length - n);
//S.C: O(1);
class Solution {
public:
    int llLength(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = (llLength(head)+1) - n;
        if(pos == 1){ 
            ListNode* first = head;
            head = head -> next;
            delete first;
            return head;
        }
        ListNode* temp = head;
        int cnt = 1;
        while(cnt < pos - 1){
            cnt++;
            temp = temp -> next;
        }
        ListNode* toDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete(toDelete);

        return head; 
    }
};


//Optimal Approach:
//T.C: O(length);
//S.C: O(1);
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode();
        prev -> next = head;
        ListNode* slow = prev;
        ListNode* fast = prev;

        while(n--) fast = fast -> next;
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete(delNode);

        return prev -> next;
    }
};