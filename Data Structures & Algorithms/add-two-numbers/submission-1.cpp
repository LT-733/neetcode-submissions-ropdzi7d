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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 and !l2) return nullptr;
        int carry = 0;
        ListNode* cur1 = l1, *cur2 = l2;
        ListNode *res = new ListNode(((cur1->val + cur2->val) >= 10) ? ((cur1->val + cur2->val) - 10) : (cur1->val + cur2->val));
        carry = ((cur1->val + cur2->val) >= 10) ? 1 : 0;
        cur1 = cur1->next, cur2 = cur2->next;
        ListNode *cur = res;
        while(cur1 || cur2){
            if(cur1 and cur2){
                int curval = ((cur1->val + cur2->val) >= 10) ? ((cur1->val + cur2->val) - 10) : (cur1->val + cur2->val);
                curval = (curval + carry >= 10) ? (curval + carry - 10) : (curval + carry);
                cout<<curval<<endl;
                carry = ((cur1->val + cur2->val) >= 10) ? 1 : 0;
                cur->next = new ListNode(curval);
                cur1 = cur1->next;
                cur2 = cur2->next;
            } else if(cur1){
                int curval = 0;
                bool needscarry = false;
                if (((cur1->val + carry) >= 10)){
                    needscarry = true;
                    curval = cur1->val + carry - 10;
                } else{
                    curval = cur1->val + carry;
                }
                cout<<curval<<endl;
                carry = (needscarry) ? 1:0;
                cur->next = new ListNode(curval);
                cur1 = cur1->next;
            } else if(cur2){
                int curval = 0;
                bool needscarry = false;
                if (((cur2->val + carry) >= 10)){
                    needscarry = true;
                    curval = cur2->val + carry - 10;
                } else{
                    curval = cur2->val + carry;
                }
                cout<<curval<<endl;
                carry = (needscarry) ? 1:0;
                cur->next = new ListNode(curval);
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if(carry) cur->next = new ListNode(1);
        return res;
    }
};
