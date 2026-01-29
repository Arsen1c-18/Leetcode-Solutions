class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            second->next = curr;
            curr->next = nextPair;

            if (prev) prev->next = second;

            prev = curr;
            curr = nextPair;
        }
        return newHead;
    }
};
