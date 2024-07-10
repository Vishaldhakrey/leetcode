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
    bool isPalindrome(ListNode* head) {
        // vector<int>st;
        // ListNode* temp = head;

        // while(temp!=NULL){
        //     st.push_back(temp->val);
        //     temp = temp->next;
            
        // }

        // int left = 0;
        // int right = st.size()-1;
        
        // while(left<=right){
        //     if(st[left]==st[right]){
        //         left++;
        //         right--;
        //         if(left>right) return true;
        //     }
        //     else{
        //         return false;
        //     }
           
        // }

        ListNode *fast = head, *slow = head, *temp, *prev;

        if(head->next == NULL) return true;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
        prev = slow;
        slow = slow->next;
        prev->next = NULL;

        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        } 
        fast = head;
        slow = prev;
        while(slow){
            if(slow->val!=fast->val) return false;
            else{
                fast = fast->next;
                slow = slow->next;
            }
        }

        return true;
    }
};