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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) return nullptr;
        ListNode* curr1 = list1, *curr2 = list2;
        ListNode* final, *currf;
        if(!curr1) return curr2;
        if(!curr2) return curr1;
        ListNode* next1 = curr1->next, *next2 = curr2->next;
        if(curr1->val <= curr2->val){
            final = curr1;
            // final->next = curr2;
            curr1 = next1;
            // curr2 = next2;
        }else{
            final = curr2;
            // final->next = curr1;
            // curr1 = next1;
            curr2 = next2;
        }
        currf = final;
        while(curr1 or curr2){
            if(!curr1){
                currf->next = curr2;
                curr2 = curr2->next;
                // cout<<"continue"<<endl;
            }else if(!curr2){
                currf->next = curr1;
                curr1 = curr1->next;
            }else {
                if(curr1->val <= curr2->val){
                    next1 = curr1->next;
                    currf->next = curr1;
                    curr1 = next1;
                }else{
                    next2 = curr2->next;
                    currf->next = curr2;
                    curr2 = next2;
                }
            }
            currf = currf->next;
        }
        return final;
    }
};
