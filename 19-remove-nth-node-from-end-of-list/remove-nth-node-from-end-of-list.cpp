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
        if(head==nullptr){
            return nullptr;
        }
        int size=0;
        ListNode* curr = head;

        while(curr != nullptr){
            curr= curr->next;
            size++;

        }
        int traverse = size-n-1;
        if(traverse == -1){
            return head->next;
        }
        curr = head;
        int i=0;
        while(i<traverse){
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
        return head;
        
        
    
    }
};