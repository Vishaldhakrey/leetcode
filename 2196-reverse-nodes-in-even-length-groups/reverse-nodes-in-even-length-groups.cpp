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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* curr1 = head;
        ListNode* prev = dummy;;
        ListNode* nextptr = nullptr;

        int group=1;
        while(curr!=nullptr){
            
            ListNode* prevLast = prev;
            ListNode* sublist_first = curr;
            int length = 0;
            while(curr1!=nullptr && length<group)
            {
                curr1 = curr1->next;
                length++;
            }

            if(length%2 != 0){
                for(int i=0; i<length; i++){
                    prev = curr;
                    curr=curr->next;
                }
            }
            else{
                int i=0;
                while(curr!=nullptr && i<length){
                    nextptr = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextptr;
                    i++;
                }
                prevLast->next = prev;
                sublist_first->next = curr;

                prev = sublist_first;
            }

            
            group++;

        }
        return dummy->next;
    }
};