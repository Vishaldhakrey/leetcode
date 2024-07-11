/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int getDifference(ListNode *headA, ListNode *headB){
        int len1 = 0, len2 = 0;

        while(headA || headB){
            if(headA){
                ++len1;
                headA = headA->next;
            }
            if(headB){
                ++len2;
                headB = headB->next;
            }
        }
        return len1-len2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
      int diff = getDifference(headA, headB);
      if(diff<0){
        while(diff++!=0){
             headB = headB->next;
        }
      }
      else{
        while(diff--!=0){
             headA = headA->next;
        }
      }
      while(headA){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
      }
      return headA;
    }
};