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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        //iterate to kth node from start
        while(k!=1) {
            fast=fast->next;
            k--;
        }
        ListNode* curr=fast;
        //iterate curr till last node along with slow
        while(curr->next!=NULL) {
            slow=slow->next;
            curr=curr->next;
        }
        //swap the value
        swap(fast->val,slow->val);
        return head;
    }
};
