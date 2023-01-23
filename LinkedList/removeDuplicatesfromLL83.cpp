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
        unordered_map<int,bool> mp;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr) {
            //check the node is duplicate or not
            if(mp.find(curr->val)!=mp.end()) {//duplicates
                //find the next curr which not duplicate
                ListNode* temp=curr;
                while(temp->val==curr->val && temp->next!=NULL) {
                    temp=temp->next;
                }
                if(temp->val!=curr->val) {
                mp[temp->val]=true;
                prev->next=temp;
                prev=temp;
                curr=temp->next;
                }
                else {
                    prev->next=NULL;
                    break;
                }
            }
            else {
                mp[curr->val]=true;
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
