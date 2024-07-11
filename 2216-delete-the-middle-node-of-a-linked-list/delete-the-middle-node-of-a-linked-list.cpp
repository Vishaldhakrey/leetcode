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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr ){
            return head;
        }
        if(head->next == nullptr){
            head=nullptr;
            return head;
        }
        // ListNode* ptr = head;
        // int count = 1;
        // while(ptr->next != nullptr){
        //     ptr = ptr->next;
        //     count++;
        // }

        // ListNode* ptr1 = head;
        // int mid = count/2;
        // for(int i=0; i<mid-1; i++){
        //     ptr1 = ptr1->next;
        // }
        // ptr1->next = ptr1->next->next;
        // return head;

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prev;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        return head;

    }

};