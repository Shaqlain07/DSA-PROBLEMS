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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        ListNode* newHead=NULL;
        while(curr) {
            bool flag=true;
            while(curr->next && curr->val==curr->next->val) {
                    flag=false;
                    curr=curr->next;
            }
            if(flag==false) {
                curr=curr->next;
            }
            else {
                if(prev==NULL) {
                    newHead=curr;
                    prev=curr;
                }
                else {
                    prev->next=curr;
                    prev=curr;
                }
                curr=curr->next;
                prev->next=NULL;
                
                
            }
        }
        return newHead;
    }
};
