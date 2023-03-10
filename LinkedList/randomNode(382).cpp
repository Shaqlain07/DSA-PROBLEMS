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
    int l;
    unordered_map<int,int> mp;
    Solution(ListNode* head) {
        ListNode* temp=head;
        int i=0; l=0;
        while(temp) {
            mp[i]=temp->val;
            i++;l++;temp=temp->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%l;
        return mp[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
