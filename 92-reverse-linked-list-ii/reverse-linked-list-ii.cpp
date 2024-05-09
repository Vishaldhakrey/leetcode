class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;  
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextPtr = nullptr;
        int i=0;

        while (curr!=nullptr && i<left-1){
            prev = curr;
            curr = curr->next;
            ++i;
        }
       i=0;
        ListNode* lastPtr_sublist = prev;
        ListNode* firstPtr_subList = curr;

        while (curr!=nullptr && i<right-left+1){
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
            ++i;
        }

        if(lastPtr_sublist != nullptr){
            lastPtr_sublist->next = prev;
        }
        else{
            head = prev;
        }
        firstPtr_subList->next = curr;
        return head;
    }
    
};
