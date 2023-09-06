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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //find no of element in list
        int cnt=0;
        ListNode* temp=head;
        while(temp) {
            cnt++;
            temp=temp->next;
        }
        int window=cnt/k;
        int rem=cnt%k;

        vector<ListNode*> res;
        if(window==0) {
            temp=head;
            int m=k;
            while(m--) {
                if(temp) {
                    ListNode* a=temp->next;
                    temp->next=NULL;
                    res.push_back(temp);
                    temp=a;
                }
                else {
                    ListNode* b=NULL;
                    res.push_back(b);
                }
            }
            return res;
        }
        temp=head;
        ListNode* dummy=temp;
        int c=0;
        while(temp) {
            c++;
            if(c==window) {
                //check for remainder
                if(rem!=0) {
                    temp=temp->next;
                    rem--;
                }
                ListNode* a=temp->next;
                temp->next=NULL;
                res.push_back(dummy);
                dummy=a;
                temp=dummy;
                c=0;
            }
            else {
                temp=temp->next;
            }
        }
        return res;
    }
};
