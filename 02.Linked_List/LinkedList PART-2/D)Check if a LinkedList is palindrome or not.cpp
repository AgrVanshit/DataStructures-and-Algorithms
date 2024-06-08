//*****https://leetcode.com/problems/palindrome-linked-list/description/*****


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
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL){
            if(temp -> val != st.top()) return false;
            temp = temp -> next;
            st.pop();
        }
        return true;
    }
};


//Optimal Approach:
//T.C: O(2*n);
//S.C: O(1);
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reverseLL(slow -> next);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first -> val != second -> val){
                reverseLL(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }

        reverseLL(newHead);
        return true;
    }
};



//Recursive Approach:
class Solution {
public:
    ListNode* curr;
    bool recur(ListNode* head){
        if(head == NULL) return true;

        bool ans = recur(head -> next);

        if(head -> val != curr -> val) return false;

        curr = curr -> next;

        return ans;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return recur(head);
    }
};