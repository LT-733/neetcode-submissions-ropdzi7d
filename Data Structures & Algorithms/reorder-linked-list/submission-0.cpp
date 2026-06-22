class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 1. Find the middle
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prevHalf = nullptr; // Track the node before slow
        
        while (fast && fast->next) {
            prevHalf = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // CRITICAL: Cut the link between the first and second half
        if (prevHalf) {
            prevHalf->next = nullptr;
        }

        // 2. Reverse the second half
        ListNode* midpoint = slow;
        ListNode* prev = nullptr;
        while (midpoint) {
            ListNode* newhead = midpoint->next;
            midpoint->next = prev;
            prev = midpoint;
            midpoint = newhead;
        }
        
        // 3. Interleave the two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // This is the head of the reversed half
        
        while (firstHalf && secondHalf) {
            ListNode* nextHead = firstHalf->next;
            ListNode* nextMid = secondHalf->next;

            firstHalf->next = secondHalf;
            if (nextHead) {
                secondHalf->next = nextHead;
            }

            firstHalf = nextHead;
            secondHalf = nextMid;
        }
    }
};