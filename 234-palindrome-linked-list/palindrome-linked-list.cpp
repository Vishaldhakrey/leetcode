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
        vector<int>st;
        ListNode* temp = head;

        while(temp!=NULL){
            st.push_back(temp->val);
            temp = temp->next;
            
        }

        int left = 0;
        int right = st.size()-1;
        
        while(left<=right){
            if(st[left]==st[right]){
                left++;
                right--;
                if(left>right) return true;
            }
            else{
                return false;
            }
           
        }

        return true;
    }
};