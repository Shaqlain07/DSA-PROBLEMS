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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        //iterate fast to n+1 node from start so to have a diff of n+1 from slow
        for(int i=1;i<=n;i++) {
            fast=fast->next;
        }
        //if it is first node
        if(fast==NULL) {
            return head->next;
        }
        //now iterate both till last node
        while(fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
