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
    ListNode* sortList(ListNode* head) {
        
        vector<int>st;

        if(head == nullptr || head->next ==  nullptr) return head;

        ListNode* temp = head;

        while(temp){
            st.push_back(temp->val);
            temp = temp->next;
        }

        sort(st.begin(), st.end());

        temp = head;

        for(int i=0; i<st.size(); i++){
            temp->val = st[i];
            
            temp = temp->next;
        }

        return head;
    }
};