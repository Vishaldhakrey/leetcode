class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto curr = head;
        auto dummy = new ListNode(0) ;
        dummy->next = head;
        auto leftPrev = dummy;
       
        for(int i=0; i<left-1; i++){
            leftPrev = curr;
            curr = curr->next;
        }
        ListNode* prev = nullptr; // Corrected null to nullptr
        for(int i=0; i<right-left+1; i++){
             ListNode* store = curr->next;
            curr->next = prev;
            prev = curr;
            curr = store;
        }

        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy->next;

    }
};
