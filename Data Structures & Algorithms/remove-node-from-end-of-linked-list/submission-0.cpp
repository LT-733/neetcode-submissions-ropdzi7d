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
        ListNode* cur = head;
        int l = 0;
        while(cur){
            ++l;
            cur = cur->next;
        }
        int target = l - n;
        if(target == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        cout<<target<<endl;
        int totarget = 0;
        cur = head;
        while(totarget < target-1){
            cur = cur->next;
            ++totarget;
        }
        ListNode *del = cur->next;
        cur->next = (cur->next == nullptr) ? nullptr : cur->next->next;
        delete del;
        return head;
    }
};
