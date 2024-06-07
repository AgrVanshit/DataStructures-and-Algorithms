//*****https://leetcode.com/problems/add-two-numbers/description/*****


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


//Approach 1:
//T.C: O(max(n1, n2)); // n -> length of list.
//S.C: O(max(n1, n2));
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 !=  NULL || l2 != NULL || carry != 0){
            int sum = 0;
            if(l1 != NULL){
              sum = sum + l1 -> val;
              l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum = sum + l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp -> next = node;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};


 /*Approach 2: Not using extra list to store the sum, 
               here we are using the longest of the two
               list to store the answer, but it as not 
               good as we are manipulating the user data. */
 //T.C: O(count1 + count2) + O(max(count1, count2));
 //S.C: O(1);
class Solution {
public:
    ListNode* addLists(ListNode* l1, ListNode* l2){
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;
        int carry = 0;
        while(temp1 !=  NULL || temp2 != NULL){
            int sum = 0;
            if(temp1 != NULL){
              sum = sum + temp1 -> val;
              prev = temp1;
              temp1 = temp1 -> next;
            }
            if(temp2 != NULL){
                sum = sum + temp2 -> val;
                temp2 = temp2 -> next;
            }
            sum += carry;
            carry = sum/10;
            prev -> val = sum%10;
        }

        if(carry != 0){
            ListNode* newnode = new ListNode(1);
            prev -> next = newnode;
        }

        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int count1 = 0;
        int count2 = 0;

        while(temp1){
            count1++;
            temp1 = temp1 -> next;
        }

        while(temp2){
            count2++;
            temp2 = temp2 -> next;
        }

        if(count1 > count2){
            return addLists(l1, l2);
        }
        else{
            return addLists(l2, l1);
        }       
    }
};