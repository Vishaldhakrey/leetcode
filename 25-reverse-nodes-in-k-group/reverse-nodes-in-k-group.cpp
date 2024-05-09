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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
    
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextptr = nullptr;

        while(true){

            ListNode* cursor = curr;
            for(int i=0; i<k; i++){
                if(cursor == nullptr) return head;
                cursor = cursor->next;
            }
            ListNode* prevLast = prev;
            ListNode* sublist_first = curr;
        

            for(int i=0; i<k; ++i){
                nextptr = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextptr;
            }

            if(prevLast!=nullptr){
                prevLast->next = prev;
            }
            else{
                head = prev;
            }

           sublist_first->next=curr;
            if(curr == nullptr ){
                break;
            }
            prev = sublist_first;
        }
        return head;
      
    }
};