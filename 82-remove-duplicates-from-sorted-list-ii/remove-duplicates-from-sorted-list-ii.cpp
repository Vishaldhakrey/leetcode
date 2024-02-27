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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr){
            if(curr->val == curr->next->val){
                while(curr->next != nullptr && curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }

};