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
    int getDecimalValue(ListNode* head) {
        //iterate on LL & store the data in vector
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head=head->next;
        }
        reverse(v.begin(),v.end());
        //iterate on vector
        int ans=0;
        int temp=1;
        for(int i=0;i<v.size();i++) {
            ans+=temp*v[i];
            temp=temp*2;
        }
        return ans;
    }
};
