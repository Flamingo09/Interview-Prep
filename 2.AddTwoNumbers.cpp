//Problem Path: https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = NULL;
        ListNode* root = NULL;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            ListNode* temp = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            if(root != NULL){
                prev->next = temp;
            }
            else {
                root = temp;
            }
            prev = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 != NULL){
            if(root != NULL) {
                prev->next = l1;
            }
            else {
                root = l1;
            }
            prev = l1;
            if(carry != 0){
                int x = prev->val + carry;
                carry = (x)/10;
                prev->val = x%10; 
            }
        }
        if(l2 != NULL){
            if(root != NULL)
                prev->next = l2;
            else
                root = l2;
            prev = l2;
            if(carry != 0){
                int x = prev->val + carry;
                carry = (x)/10;
                prev->val = x%10; 
            }
        }
        while(carry != 0) {
            if(prev->next == NULL && carry!=0)
                prev->next = new ListNode(0);
            prev = prev->next;
            
            int x = prev->val + carry;
            carry = (x)/10;
            prev->val = x%10;
        }
        return root;
    }
};
