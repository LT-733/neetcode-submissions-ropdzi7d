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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!k) return head;
        if(!head) return nullptr;
        vector<ListNode*> heads;
        heads.push_back(head);
        int gauge = 0;
        ListNode* cur = head;
        while(cur){
            ++gauge;
            if(gauge == k){
                gauge = 0;
                heads.push_back(cur->next);
                ListNode* prev = cur;
                cur = cur->next;
                prev->next = nullptr;
                // we either add the next head to our tracked reversals,
            }else{
                cur = cur->next;
                // or we simply proceed as the threshold is not reached
            }
        }
        bool leaveasis = false;
        ListNode* last = heads.back();
        gauge = 0;
        while(last){
            ++gauge;
            last = last->next;
        }
        if(gauge < k) leaveasis = true;
        for(int i = 0; i < heads.size(); ++i){
            if(i == heads.size()-1){
                if(!leaveasis) heads[i] = reverseList(heads[i]);
            }else{
                heads[i] = reverseList(heads[i]);
            }
        }
        ListNode* res = heads[0], *curres = heads[0];
        cout<<res->val<<endl;
        for(int i = 0; i < heads.size()-1; ++i){
            while(curres->next) curres = curres->next;
            cout<<res->val<<endl;
            curres->next = heads[i+1];
            curres = curres->next;
        }
        return res;
    }
};
