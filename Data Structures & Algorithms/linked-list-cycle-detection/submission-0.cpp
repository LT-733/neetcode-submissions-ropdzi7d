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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast and slow){
            if(fast) fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }else return false;
            if(fast == slow) return true;
        }
        return false;
    }
};
