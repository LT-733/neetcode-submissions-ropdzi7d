class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* fast = head, *slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
            // cout<<"loop"<<endl;
        }
        ListNode *midpoint = slow;
        ListNode *del = head;
        while(del->next != midpoint) del = del->next;
        ListNode *l2 = midpoint, *l1 = head;
        del->next = nullptr;
        ListNode *rev = l2;
        ListNode *prev = nullptr;
        while(rev){
            // cout<<"loop"<<endl;
            ListNode *tmp = rev->next;
            rev->next = prev;
            prev = rev;
            rev = tmp;
        }
        l2 = prev;
        // ListNode *temp = l2;
        // while(temp){
        //     cout<<temp<<"->";
        // }cout<<"nullptr"<<endl;
        while(l1 and l2){
            ListNode *l1next = l1->next, *l2next = l2->next;
            l1->next = l2;
            l2->next = l1next;
            l1 = l1next;
            l1next = l1->next;
            l2 = l2next;
            l2next = l2->next;
        }
    }
};