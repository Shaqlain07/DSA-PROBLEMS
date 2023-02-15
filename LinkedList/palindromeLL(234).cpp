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
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head ==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* agla;
        while(curr) {
            agla=agla->next;
            curr->next=prev;
            prev=curr;
            curr=agla;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //find the mid of LL using slow and fast pointer
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid;
        if(slow->next==NULL) {
            mid=slow;
        }
        else {
        if(fast!=NULL) {//odd
            mid=slow->next;
        }
        }
        ListNode* curr=reverse(mid);
        //Now,iterate through the mid of the list and starting and compare
        while(curr) {
            if(head->val!=curr->val) return false;
            curr=curr->next;
            head=head->next;
        }
        return true;
    }
};
